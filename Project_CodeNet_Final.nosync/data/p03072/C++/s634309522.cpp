#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
using ll = long long;
using namespace std;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
//sort(a, a + N, greater<ll>())   // descend
//sort(a, a+N)                    //  ascend

/* 
void comb(vector<vector <ll> > &v) {
	ll mod=1000000007;
	rep (i,0,v.size()) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	rep (k,1,v.size()) {
		rep (j,1,k) {
			v[k][j] = (v[k - 1][j - 1] + v[k - 1][j])%mod;
		}
	}
}
/*main内でnCn~nC0 生成 **
vector<vector<ll> > v(n + 1, vector<ll>(n + 1, 0));
comb(v);
*/

int main(){
	ll n;
	cin>>n;
	ll h[30];
	rep(i,0,n) cin>>h[i];
	ll cnt=1;
	ll m=h[0];
	rep(i,1,n) {
		if(h[i]>=m) cnt++;
		m=max(m,h[i]);
	}
	cout<<cnt;
}