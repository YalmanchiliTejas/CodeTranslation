//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

struct mint {
  LL x; 
  mint(LL x=0):x((x%mod+mod)%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(LL t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

string K;
int D;

LL ans = 0;

void solve(){
	int N = (int)K.size();
	//上からi桁目まで見るとき、(0<=i<=N-1)
	//と決めたとき各桁の和をDで割ったあまりがjになる数
	//がいくつあるかをdp[i][j][t]とおく
	//だたしそこまでの桁がKと一致していればt=1
	//していなければt=0
	//といった風に分ける
	const int MATCH = 1;
	const int NOT_MATCH = 0;
	vector<vector<vector<mint>>> dp(N,vector<vector<mint>>(D,vector<mint>(2,0)));

	for(int i=0;i<K[0]-'0';i++){
		dp[0][i%D][NOT_MATCH] += mint(1);
	}
	dp[0][(K[0]-'0')%D][MATCH] += mint(1);

	//配るDP
	for(int i=0;i<=N-2;i++){
		int next_digit = K[i+1]-'0';//今見てる桁よりひとつ進んだとこの数
		//NOT_MATCHから配る
		for(int j=0;j<D;j++){
			for(int d=0;d<10;d++){
				dp[i+1][(j+d)%D][NOT_MATCH] += dp[i][j][NOT_MATCH];
			}
		}
		//MATCHから配る
		for(int d=0;d<next_digit;d++){
			for(int j=0;j<D;j++){
				dp[i+1][(j+d)%D][NOT_MATCH] += dp[i][j][MATCH];
			}
		}
		for(int j=0;j<D;j++){
			dp[i+1][(j+next_digit)%D][MATCH] += dp[i][j][MATCH];
		}
	}

	// cout << "NOT_MATCH" << endl;
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<D;j++){
	// 		cout << dp[i][j][NOT_MATCH].x << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	// cout << "MATCH" << endl;
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<D;j++){
	// 		cout << dp[i][j][MATCH].x << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	ans = (dp[N-1][0][MATCH] + dp[N-1][0][NOT_MATCH] - mint(1)).x;
}
 
int main(){
    cin >> K;
    cin >> D;
 
    solve();

    cout << ans << endl;
    return 0;
}