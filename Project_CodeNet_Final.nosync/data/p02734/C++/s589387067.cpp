#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<complex>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using Complex = complex<double>;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1145141919810364364LL;
double PI = acos(-1.0);
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)


ll mod = 998244353;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	ll N, S;
	cin >> N >> S;
	vector<vector<ll>>dp(2,vector<ll>(S+1));
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ll A;
		cin >> A;
		for (int j = 0; j <= S; j++)dp[1][j] = 0;
		for (int j = 0; j <= S; j++) {
			dp[1][j] = dp[0][j];
			if (j - A >= 0)dp[1][j] += dp[0][j - A];
			if (j == A)dp[1][j] += 1;
			if (j == 0)dp[1][j] += 1;
			dp[1][j] %= mod;
		}
		ans = ans + dp[1][S];
		ans %= mod;
		swap(dp[0], dp[1]);
	}
	puts(ans);

	return 0;
}