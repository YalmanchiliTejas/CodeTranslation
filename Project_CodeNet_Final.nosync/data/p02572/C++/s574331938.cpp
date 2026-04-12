#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define mod (1000000007)

void solve() 
{
    int n;cin>>n;
    ll a[n];REP(i,n)cin>>a[i];
    ll sum=0;REP(i,n)(sum+=a[i])%=mod;
    (sum*=sum)%=mod;
    REP(i,n) sum-=(a[i]*a[i])%mod,sum+=(sum<0?mod:0);
    cout<<(sum*(mod+1)/2)%mod<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}