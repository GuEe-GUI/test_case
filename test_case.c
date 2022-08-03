#include <test_case.h>
#include <stdio.h>

TEST_CASE_DEFINE(test_case_placeholder, NULL, NULL, NULL);
static struct test_case *_test_case_start = NULL, *_test_case_end = NULL;

int test_case_init()
{
    _test_case_start = _test_case_end = (void *)&test_case_placeholder;

    for (;;)
    {
        if ((_test_case_start - 1) != NULL && (*(_test_case_start - 1)).magic != TEST_CASE_MAGIC)
        {
            break;
        }
        --_test_case_start;
    }

    for (;;)
    {
        if ((_test_case_end + 1) != NULL && (*(_test_case_end + 1)).magic != TEST_CASE_MAGIC)
        {
            break;
        }
        ++_test_case_end;
    }

    return 0;
}

void test_case_start()
{
    struct test_case *test_case_ptr = _test_case_start;

    while (test_case_ptr <= _test_case_end)
    {
        if (test_case_ptr->handler != NULL)
        {
            printf("[ %s ] %s %s\n", test_case_ptr->handler() ? " FAIL  " : "SUCCESS", test_case_ptr->name, test_case_ptr->info);
        }
        ++test_case_ptr;
    }
}
