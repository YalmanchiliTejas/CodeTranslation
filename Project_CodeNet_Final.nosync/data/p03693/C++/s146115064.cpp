#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 1e5 + 10;

int a , b , c;
int ans;

int main()
{
    scanf("%d%d%d" , &a , &b , &c);
    ans = a * 100 + b * 10 + c;
    if(ans % 4 == 0)
        printf("YES");
    else
        printf("NO");
}
