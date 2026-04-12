#include <stdio.h>
/*#include <stdlib.h>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <forward_list>*/
using namespace std;

#define SCAN_INT(i) scanf("%lld", i)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define PRINT_INT(i) printf("%lld\n", i)
#define PRINT_TWO_INT(i, j) printf("%d %d\n", i, j)
#define PRINT_THREE_INT(i, j, k) printf("%d %d %d\n", i, j, k)

int main()
{
    char ss[3];
    scanf("%s", ss);

    bool flag = false;
    for (int i = 0; i < 2; i++)
    {
        if (ss[i] != ss[i + 1])
        {
            flag = true;
            break;
        }
    }

    if (flag)
        printf("Yes");
    else
        printf("No");
    return 0;
}