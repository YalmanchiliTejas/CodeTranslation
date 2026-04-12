#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

ll gcd(ll n, ll m) {
	ll tmp;
	while (m!=0) {
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m) {
	return abs(n * m) / gcd(n, m);//gl=xy
}
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
using namespace std;

//ここから

ll dd;
//桁DP
ll digit_dp(string s){
  ll dp[s.size()+1][2][105];//上からi桁までjはNのi桁未満かそうでないか、kは問題の条件に応じて変化するboolean
  memset(dp,0,sizeof(dp));
  dp[0][0][0]=1;
  rep(i,s.size()) {//桁数が大きいのでstringで読み取り、各位ごとに数字に変換する
		int D = s[i] - '0';
		rep(j,2) {
			rep(k,dd) {
				for (int d = 0; d <= (j ? 9 : D); ++d){//i桁目がNのi桁目より小さければ9まではいる。そうでなければNのi桁目の数字以下が入る
					dp[i + 1][j || d < (j ? 9 : D)][(k+d)%dd] += dp[i][j][k];
          dp[i + 1][j || d < (j ? 9 : D)][(k+d)%dd]%=mod;
					}
			}
		}
	}
  //N未満ならdp[s.size()][1][条件]だけでよい
  return (dp[s.size()][0][0]+dp[s.size()][1][0]-1LL+mod)%mod;//0の場合を引いておく,modを足すのを忘れない
}

void solve(){
  string s;
  cin>>s>>dd;
  cout<<digit_dp(s)<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}