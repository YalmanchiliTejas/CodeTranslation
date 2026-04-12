#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;

int a[maxn],b[maxn],n;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(a,a+n);
    int midr=a[n/2],midl=a[n/2-1];

    for (int i=0;i<n;i++)
    {
        if (b[i]<midr) printf("%d\n",midr);
        else printf("%d\n",midl);
    }

    return 0;
}
