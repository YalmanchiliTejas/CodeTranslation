#include<bits/stdc++.h>
using namespace std;

int n, p, Res;

int M(int x, int y)
{
    if ((x) && (!y)) return 0;
    return 1;
}

int main()
{
    scanf("%d", &n); getchar();
    for (int i=1; i<=n; i++)
    {
        char c;
        scanf("%c", &c); getchar();
        if (c == 'T') p = 1; else p = 0;
        if (i == 1) Res = p;
        if (i >= 2)
            Res = M(Res, p);
    }
    puts((Res)?("T"):("F"));
}

