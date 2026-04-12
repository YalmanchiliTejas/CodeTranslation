#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <math.h>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vvvl vector<vector<vector<ll> > >
#define vd vector<double>
#define vvd vector<vector<double> >
#define vvvd vector<vector<vector<double> > >
#define rep(i,a) for(ll i = 0;i<a;++i)
#define mod 1000000007
#define inf 11451419198
using namespace std;

ll dp[101][4][2];

int main(){
	rep(i, 101) rep(j, 4) rep(k, 2) dp[i][j][k] = 0;
	string s; cin >> s;
	ll n = s.size(), K; cin >> K;
	dp[0][0][0] = 1;
	rep(i, n) rep(j,4) rep(k,2){
		ll x = s[i] - '0';
		rep(a, 10){
			ll ni = i + 1, nj = j, nk = k;
			if (a) nj++;
			if (nj > K) continue;
			if (k == 0){
				if (a > x) continue;
				if (a < x) nk = 1;
			}
			dp[ni][nj][nk] += dp[i][j][k];
		}
	}cout << dp[n][K][0] + dp[n][K][1] << endl;
	return 0;
}