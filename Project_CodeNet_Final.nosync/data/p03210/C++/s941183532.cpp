#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(void)
{
    int n;
    scanf("%d", &n);

    if(n == 7 || n == 5 || n == 3)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
