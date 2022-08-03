#ifndef __TEST_CASE_H__
#define __TEST_CASE_H__

struct test_case
{
    unsigned long magic;
    const char *name;
    const char *info;
    int (*handler)(void);
} __attribute__((packed));

#define LINE_VAR(a)         __LINE_LINK(a, __LINE__)
#define __LINE_LINK(a, b)   __MACRO_LINK(a, b)
#define __MACRO_LINK(a, b)  a##b

#define TEST_CASE_MAGIC     0xdeadbeef

#define TEST_CASE_DEFINE(x, ...)                \
static const struct test_case x                 \
__attribute__((used,section(".test_case"))) =   \
{                                               \
    TEST_CASE_MAGIC, ##__VA_ARGS__              \
};

#define TEST_CASE(info, name)               \
int LINE_VAR(test_case_handler_)(void);     \
TEST_CASE_DEFINE(LINE_VAR(test_case_),      \
name, info, LINE_VAR(test_case_handler_))   \
int LINE_VAR(test_case_handler_)(void)

int test_case_init();
void test_case_start();

#endif /* __TEST_CASE_H__ */
