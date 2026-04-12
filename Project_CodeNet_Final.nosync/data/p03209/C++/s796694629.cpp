#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s[50],p[50];

ll f(ll n,ll x) {
    if (n==0)
        return 1;
    if (x==1)
        return 0;
    if (x<=1+s[n-1])
        return f(n-1,x-1);
    if (x==1+s[n-1]+1)
        return p[n-1]+1;
    if (x<=1+s[n-1]+1+s[n-1])
        return p[n-1]+1+f(n-1,x-2-s[n-1]);
    return 2*p[n-1]+1;
}

int main() {
    ll n,x;
    cin>>n>>x;
    s[0]=p[0]=1;
    for (int i=1;i<n;i++) {
        s[i]=s[i-1]*2+3;
        p[i]=p[i-1]*2+1;
    }
    cout<<f(n,x)<<endl;
    return 0;
}