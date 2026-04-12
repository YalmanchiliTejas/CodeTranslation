#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,a,b;
    cin>>n>>m;
    vector<vector<ll> > v(n,vector<ll> (n,0));
    for(int i=0;i<m;i++){
    	cin>>a>>b;
    	a--;b--;
    	v[a][b]=v[b][a]=1;
    }
    ll maki=(1LL<<n);
    vector<vector<ll> > dp(maki,vector<ll> (n,0));
    dp[1][0]=1;
    for(int bit=1;bit<maki;bit++){
    	for(int i=0;i<n;i++)if(bit>>i&1){
    		ll mask=bit-(1LL<<i);
    		for(int j=0;j<n;j++)if(mask>>j&1 && v[i][j])dp[bit][i]+=dp[mask][j];
    	}
    }
    ll ans = 0;
    for(int i=1;i<n;i++)ans+=dp[maki-1][i];
    cout << ans << endl;
    return 0;
}
