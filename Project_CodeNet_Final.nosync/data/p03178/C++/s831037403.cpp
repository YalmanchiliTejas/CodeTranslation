#include<iostream>
#include<functional>
#include<utility>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<list>
using namespace std;
constexpr auto MOD = 1000000007;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;

int d;

long long mod(const long long &a) {
   if (a >= 0)return a % 1000000007;
   return 1000000007 - (-a) % 1000000007;
}
int mod(const int &a) {
   if (a >= 0)return a % 1000000007;
   return 1000000007 - (-a) % 1000000007;
}

int main() {
   string s;
   cin >> s >> d;
   int k = s.size();
   vector<vector<vector<ll>>> dp(k + 1, vector<vector<ll>>(2, vector<ll>(d, 0)));//i桁まで確定、K以下?、%D
   dp[k][0][0] = 1;
   for (int i = k - 1; i >= 0; i--)
   {//s[i]-'0'でその桁の大きさを取り出せる
	  for (int j = 0; j < 2; j++)
	  {
		 for (int p = 0; p < d; p++)
		 {
			if (!dp[i + 1][j][p])continue;//dp[i+1][j][p]をどこに加算するか?
			for (int l = 0; l <= 9; l++)//i桁目の数
			{
			   if (!j&&l == s[k - i - 1] - '0')dp[i][j][(l + p) % d] = mod(dp[i][j][(l + p) % d] + dp[i + 1][j][p]);
			   if (!j&&l < s[k - i - 1] - '0')dp[i][1][(l + p) % d] = mod(dp[i][1][(l + p) % d] + dp[i + 1][j][p]);
			   if (j)dp[i][j][(l + p) % d] = mod(dp[i][j][(l + p) % d] + dp[i + 1][j][p]);
			}
		 }
	  }
   }
   cout << mod(dp[0][1][0] + dp[0][0][0] - 1 + MOD) << endl;
   cin >> s;
}