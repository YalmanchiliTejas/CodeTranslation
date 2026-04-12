#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<int,int>
#define iil pair<ll,ll>
#define se second
#define ld long double
#define mod 1000000007
#define popcount __builtin_popcountll
#define x0 zxcxzcsacasd
#define x1 ghfghujfgfg
#define y0 olkjhdnncvcv
#define y1 bhvgrewm345345435
#define debug(x) std::cerr<<#x<<": "<<(x)<<'\n'
#define all(x) x.begin(), x.end()
using namespace std;
void test_case(){
	ll n, x, m;
	cin>>n>>x>>m;
	ll amid = x;
	map<ll, ll>cnt;
	vector<ll>v;
	v.pb(x);
	int len = 0;
	ll rem = n - 1;
	for(ll i=1;i<n;i++){
		ll a = v[i-1];
		cnt[a] = i - 1;
		a*=a;
		a = a%m;
		if(cnt.count(a)){
			len = 0;
			ll s = 0;
			int l = v.size();
			for(int i=cnt[a];i<l;i++){
				s+=v[i];
				len++;
			}
			ll c = rem / len;
			amid+=c * s;
			rem%=len;
			for(int i = cnt[a];rem;i++, rem--){
				amid+=v[i];
			}
			cout<<amid<<endl;
			return;
		}
		rem--;
		amid+=a;
		v.pb(a);
	}
	cout<<amid<<endl;
}
int main(){
	int t = 1;
	// scanf("%d", &t);
	while(t--)test_case();
}
