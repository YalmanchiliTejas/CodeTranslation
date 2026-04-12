#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int dp[110][4][2];

int main(){
	string s;
	int K;
	cin >> s >> K;
	int N = s.size();
	dp[0][0][0] = 1;
	rep(i,N){
		rep(j,4){
			rep(k,2){
				int nd = s[i]-'0';
				rep(d,10){
					int ni = i+1, nj = j, nk = k;
					if(d != 0) ++nj;
					if(nj > K)continue;
					if(k == 0){
						if(d > nd)continue;
						if(d < nd)nk = 1;
					}
					dp[ni][nj][nk] += dp[i][j][k];
				}
			}
		}
	}
	cout << dp[N][K][0] + dp[N][K][1] << endl;
}

//ll big = 0, small = 0;
//ll lt = 0, mid = 0;
//void dfs(string now, string to, int m_len){
//	if(now.size() == m_len){
//		if(now <= to){
//			++small;
//		}else{
//			if(now.substr(0,now.size()-1) == to.substr(0, to.size()-1)){
//				++lt;		
//			}else{
//				if(to.size() == 3){
//					if(now[0] == to[0]){
//						mid ++;
//						return;
//					}
//				}
//					++big;
//			}
//		}
//	}else{
//		REP(i,9){
//			string n = now +  (char)('0' + i);
//			dfs(n, to, m_len);
//		}
//	}
//}
//
//ll comb_modM(ll n, ll r, ll M = MOD){
//	if(n == 0)return 0;
//	if(r < 0)return 0;
//  ll ans = 1; rep(i,r){ans *= (n-i); }
//  ll divisor = 1; rep(i,r){divisor *= (i+1);}
//	ans /= divisor;
//  return ans;
//}
//
//int main(){
//	string s;
//	int K;
//	cin >> s	>> K;
//	int N = s.size();
//	string t;
//	if(N >= K){
//		t = s.substr(0,K);
//	}else{
//		t = s;
//	}
//	dfs("", t, K);
//	ll ans = 0;
//	printf("[big, mid, lt, small]->[%lld, %lld, %lld, %lld]\n", big, mid, lt, small);
//	{
//		if(N-K >= 1){
//			ll kake = comb_modM(N,K);
//			ans += kake*small;
//			ans += (kake-1)*lt;
//			ans += (kake-K-1)*mid;
//		}else if(N-K == 0){
//			ans += small;
//		}
//	}
//	{
//		if(N-K-1 >= 1){
//			ans += comb_modM(N-1,K)*big;
//		}else if(N-K-1 == 0){
//			ans += big;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}
