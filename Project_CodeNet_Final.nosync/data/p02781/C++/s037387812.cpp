#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using ch = char;
using db = double;
using bl = bool;
using vll = vector<long long>;
using vdb = vector<db>;
using vvll = vector<vll>;
using vst = vector<st>;
using vch = vector<char>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
#define rep(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b;return true;} return false;}
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b;return true;} return false;}
const ll mod = 1000000007;
const ll inf = 1LL << 60;

int main(){
	st s;
	ll k, n;
	cin >> s >> k;
	n = s.size();
	vvll dp1(n + 1, vll(k + 1, 0)), dp2(n + 1, vll(k + 1, 0));
	dp2.at(0).at(0) = 1;
	rep(i, 0, n)rep(j, 0, k + 1){
		if(s.at(i) == '0'){
			dp1.at(i + 1).at(j) += dp1.at(i).at(j);
			dp2.at(i + 1).at(j) += dp2.at(i).at(j); 
			if(j < k) dp1.at(i + 1).at(j + 1) += dp1.at(i).at(j) * 9;
		}
		else{
			dp1.at(i + 1).at(j) += dp1.at(i).at(j) + dp2.at(i).at(j);
			if(j < k){
				dp1.at(i + 1).at(j + 1) += dp1.at(i).at(j) * 9 + dp2.at(i).at(j) * (s.at(i) - '1');
				dp2.at(i + 1).at(j + 1) += dp2.at(i).at(j);
			}
		}
	}

	cout << dp1.at(n).at(k) + dp2.at(n).at(k) << endl;
}