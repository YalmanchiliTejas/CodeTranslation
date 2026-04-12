#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define endl '\n'
#define y1 holyshit
#define all(x) x.begin(),x.end()
const int inf=0x3f3f3f3f;
const ll mod=1000000007;

int N;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	ll ans=0,sum=0;
	for(int i=0;i<N;i++){
		ll t; cin>>t;
		ans=(ans+sum*t)%mod;
		sum=(sum+t)%mod;
	}
	cout<<ans;
	return 0;
}