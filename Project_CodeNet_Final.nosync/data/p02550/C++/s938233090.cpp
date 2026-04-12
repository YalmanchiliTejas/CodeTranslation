#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll D = 40;

/*********************************/
template<class T> inline ostream& operator<<(ostream& os,vector<T> arr) {os << "["; for(ll i = 0; i < (ll)arr.size(); i++)os << arr[i] << (i == (ll)arr.size() - 1 ? "]" : ",");os << endl;return os;}
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A,B>& p){os << "{" << p.first << "," << p.second << "}";return os; }
#define prvec(v) cerr<<#v<<": [";for(ll __i = 0;__i < (ll)(v).size(); __i++)cerr<<((v)[__i])<<(__i+1==(ll)(v).size()?"]\n":",");
#define print(x) cerr<<#x<<": "<<(x)<<endl
/*********************************/

int main()
{
	ll n, x, mod; cin >> n >> x >> mod;
	vector<ll> arr(mod, -1); //arr[i]の初出が何項目か
	vector<vector<pair<ll,ll>>> du(D + 1, vector<pair<ll,ll>>(mod));

	for(ll i = 0; i < mod; i++) {
		ll nxt = (i * i) % mod;
		du[0][i].first = nxt;
		du[0][i].second= nxt;
	}

	for(ll i = 0; i < D; i++) {
		for(ll j = 0; j < mod; j++) {
			du[i + 1][j].first = du[i][du[i][j].first].first;
			du[i + 1][j].second= du[i][du[i][j].first].second + du[i][j].second;
		}
	}


	ll sum = x;
	ll pos = x;
	n--;
	for(ll i = 0; i < D; i++) {
		if((1LL << i) & (ll)n) {
			sum += du[i][pos].second;
			pos = du[i][pos].first;
		}
	}
	cout << sum << endl;

}