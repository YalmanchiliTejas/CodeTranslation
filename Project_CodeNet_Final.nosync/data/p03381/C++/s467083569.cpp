#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#define MAXN 200005
using namespace std;

int n, ans[MAXN];
struct A {int num, pos;} a[MAXN];

bool CMP(A x, A y)
{
    return x.num<y.num;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i].num), a[i].pos=i;
    sort(a+1, a+n+1, CMP);
    for(int i=1; i<=n; i++)
    {
        if(i<=n/2) ans[a[i].pos]=a[n/2+1].num;
        else ans[a[i].pos]=a[n/2].num;
    }
    for(int i=1; i<=n; i++) printf("%d\n", ans[i]);
}
