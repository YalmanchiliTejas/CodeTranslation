#include "bits/stdc++.h"
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;i--)
#define ALL(a) a.begin(),a.end()
template<class T>inline void out(T t){cout<<t<<"\n";}
template<class T,class... Ts>inline void out(T t,Ts... ts){cout<<t<<" ";out(ts...);}
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr long long INF = 1e9;

int dp[111][2][5];

signed main(){
	string s;int K;
	cin >> s >> K;
	dp[0][1][0] = 1;
	REP(i,s.size()){
		REP(j,2){
			int lim = j ? s[i] - '0' : 9;
			REP(k,lim+1){
				REP(l,K+1){
					dp[i+1][j&&(k==lim)][l+(k>0)]+=dp[i][j][l];
				}
			}
		}
	}
	int ans = 0;
	REP(i,2)ans+=dp[s.size()][i][K];
	out(ans);
}
