#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    int l=1,r=n;
    for(int i=n;i;i--)
    {
        if((n-i)&1) b[r--]=a[i];
        else b[l++]=a[i];
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",b[i],i==n?'\n':' ');
    return 0;
}
