/*by freesteed*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define pb push_back
#define fill(x,c) memset(x,c,sizeof(x))
#define fi first
#define se second
#define sz(A) (int)(A.size())
#define all(x) (x).begin(),(x).end()
#define caset int ___T; cin>>___T; for(int cs=1;cs<=___T;cs++)
#define get_be(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
//get_be biger & equal
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
const ll mod=1e9+7;
const ll oo=1e9+10;
const int Max = 1e6+10;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll a[Max],b[Max];
ll n,m,k,res; 
struct BIT {
private:
	vector<ll> node; int n;
public:
	void init(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, ll w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};
void solve(){
	string s;
	cin>>s;
	if(s[0]==s[1]&&s[1]==s[2]){
		cout<<"No";
	}else{
		cout<<"Yes";
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//caset{
		solve();
	//}
  	return 0;
}



