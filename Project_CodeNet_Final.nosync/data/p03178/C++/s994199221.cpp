#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#include <conio.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;

#define rep(i,n)	for(ll i=0;i<(n);i++)
#define SZ(x) ((ll)x.size())
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define F first
#define S second
#define int ll
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// const ll MOD = INT_MAX;
const double PI = acos(-1);

void openfile(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
}

const int leng = 1e4+7;
char k[leng];
const int mod = 1e9+7;

void add(int &a, int b){
	a += b;
	if(a >= mod)	a -= mod;
}

signed main(){
	IOS
	scanf("%s", k);
	int D;
	scanf("%lld", &D);
	int len = strlen(k);
	vector<vector<int>> dp(D, vector<int>(2));
	// dp[sum][b] = 
	// 		sum : current sum mod D is sum
	//		b : whether we've already chosen some digit 'smaller' than in K

	dp[0][0] = 1;
	rep(i,len){
		vector<vector<int>> dp1(D, vector<int>(2));
		rep(sum,D){
			for(bool b : {false,true}){
				rep(digit,10){
					if(digit > k[i] - '0' && !b)	break;
					add(dp1[(sum+digit) % D][b || (digit < k[i] - '0')], dp[sum][b]);
				}
			}
		}

		dp = dp1;
	}
	int ans = (dp[0][0] + dp[0][1] - 1 + mod) % mod;
	printf("%lld\n", ans);
}
