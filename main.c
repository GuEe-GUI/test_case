#include <stdio.h>

#include "test_case.h"

TEST_CASE("Main1 config test", "[Main1]")
{
    printf("I'm Main%d, I will %s.\n", 1, "success");

    return 0;
}

TEST_CASE("Main2 config test", "[Main2]")
{
    printf("I'm Main%d, I will %s.\n", 2, "fail");

    return -1;
}

int main()
{
    if (!test_case_init())
    {
        test_case_start();
    }

    return 0;
}
