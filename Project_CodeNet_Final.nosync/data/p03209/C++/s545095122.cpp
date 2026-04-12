#include <bits/stdc++.h>
using namespace std;

long f[52], p[52];

long func(int n, long x)
{
    long res=0;
    if (x<=0) return 0;
    x--;
    if (x>=f[n-1]) {
        res+=p[n-1];
        x-=f[n-1];
        if (x<=1) return res+x;
        x--;
        ++res;
        if (x>=f[n-1]) return res+p[n-1];
        return res+func(n-1, x);
    }
    return func(n-1, x);
}

int main()
{
    int n; cin>>n;
    long x; cin>>x;
    f[0]=p[0]=1;
    for(int i=1; i<=n; ++i) {
        f[i]=1+f[i-1]+1+f[i-1]+1;
        p[i]=p[i-1]+1+p[i-1];
    }
    cout<<func(n, x)<<endl;
}