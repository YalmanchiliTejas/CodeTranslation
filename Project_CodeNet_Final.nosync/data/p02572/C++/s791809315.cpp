#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll mod=1000000007;
const char nl='\n';

void solve(){
    ll i,j,k,l,m,n,u,v,x,y;
    cin>>n;
    vector<ll> vc(n+1),sm(n+1);
    sm[0]=0;
    for(i=1;i<=n;i++){
        cin>>vc[i];
        sm[i]=(vc[i]+sm[i-1])%mod;
    }
    ll ans=0;
    for(i=1;i<n;i++){
        ans= ((vc[i] * (sm[n]-sm[i]+mod)%mod)%mod + ans%mod)%mod;
    }
    cout<<ans%mod<<nl;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t = 1,i=1;
//    cin >> t;
	while (t--)
	{
//	    cout<<"Case #"<< i++ <<": ";
		solve();
	}
	return 0;
}

