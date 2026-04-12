#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrepa(i,a,n) for(int i=n-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
#define vc vector

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){

    int n;
    cin>>n;
    vi a(n);
    vl s(n+1);
    rep(i,n){
        cin>>a[i];
        s[i+1]=(s[i]+a[i])%MOD;
    }

    ll ans=0;

    repa(i,1,n){
        ll tmp=(a[i]*s[i])%MOD;
        ans=(ans+tmp)%MOD;
    }

    cout<<ans<<"\n";

    return 0;

}