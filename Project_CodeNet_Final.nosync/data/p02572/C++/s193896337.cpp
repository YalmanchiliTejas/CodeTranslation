#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    ll a[n];rep(i,n)cin>>a[i];
    ll ans = 0;
    ll MOD = 1000000007;
    ll s[n];s[0]=a[0];
    rep(i,n-1)s[i+1]=s[i]+a[i+1];
    
    rep(i,n){
        ll tmp=s[n-1]-s[i];
        tmp%=MOD;
        tmp*=a[i];
        ans+=tmp;
        ans%=MOD;
    }
    cout<<ans<<endl;
	return 0;
}