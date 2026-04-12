#include <bits/stdc++.h>
using namespace std;
const long long MD=1e9+7;
long long n,m,k,fact[200005],ans;
long long qpow(long long b,long long exp) {
    long long ret=1;
    while (exp!=0) {
        if (exp%2==1) {ret*=b; ret%=MD;}
        b*=b; b%=MD;
        exp/=2;
    }
    return ret;
}
long long xcy(int x,int y) {
    if (y>x) return 0;
    if (y==0 or y==x) return 1;
    long long nom=fact[x];
    long long de1=qpow(fact[x-y],MD-2),de2=qpow(fact[y],MD-2);
    return (((nom*de1)%MD)*de2)%MD;
}
int main() {
    cin>>n>>m>>k;
    fact[0]=1;
    for (int i=1; i<=n*m; i++) {fact[i]=fact[i-1]*i; fact[i]%=MD;}
    for (int i=0; i<=n-1; i++) {
        for (int j=0; j<=m-1; j++) {
            long long co=xcy(n*m-2,k-2);
            long long p1=1LL*j*(j+1)*(n-i-1)/2; p1%=MD;
            long long p2=1LL*m*(n-i)*(n-i-1)/2; p2%=MD;
            long long p3=1LL*(m-j)*(m-j-1)*(n-i-1)/2; p3%=MD;
            long long yval=1LL*(m-j)*(m-j-1)/2; yval%=MD;
            ans+=(co*((p1+p2+p3+yval)%MD))%MD; ans%=MD;
        }
    }
    cout<<ans<<'\n';
}