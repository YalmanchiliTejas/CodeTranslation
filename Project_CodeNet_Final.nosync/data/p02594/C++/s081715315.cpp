#include <algorithm>
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stack>
#include <map>
#define maxn 100000 + 5
#define INF 0x3f3f3f3f
#define xin(a) scanf("%d", &a)
#define ffr(i,m, n) for (i = m; i < n; i++)
#define clr(a, b) memset(a, b, sizeof(a));
#define pi acos(-1,0)
typedef double db;
typedef long long ll;
using namespace std;
void t(void)
{
    int t, n;
    xin(t);
    while (t--)
    {

    }
}
void n(void)
{
    int n, i;
    xin(n);
    cout<<(n>=30?"Yes":"No")<<endl;
}
int main(void)
{
    #ifndef ONLINE_JUDGE
    long _begin_time = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    n();
    #ifndef ONLINE_JUDGE
    long _end_time = clock();
    printf("time = %ld ms\n", _end_time - _begin_time);
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}