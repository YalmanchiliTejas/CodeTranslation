/*
Author: Xjrjyy
LANG: C++
PROG: abc177_c.cpp
Mail: admin@xjrjyy.com
Blog: https://blog.xjrjyy.cn/
*/

#include <cstdio>
#include <cctype>
#include <vector>
#include <iostream>

#define Mod 1000000007
#define MAXN ()

int n, a;
long long sum, ans;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
    	scanf("%d", &a);
    	ans = (ans + a * sum % Mod) % Mod;
    	sum = (sum + a) % Mod;
    }
    printf("%lld", ans);
    return 0;
}
