#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
//#define int long long
#define len(x) (int)(x).size()     
#define all(x) (x).begin(), (x).end()
#define test int _; cin >> _; while(_--)
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
 
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
 
inline ll gcd(ll a, ll b){while(b){ a %= b; swap(a, b); } return a; }
inline ll mod(ll a, ll b){return ((a%b)+b)%b;}
inline ll expo(ll b, ll p, ll m = MOD){
  ll ans = 1; 
  while(p > 0){
    if(p&1LL) ans = mod(ans*b, m); 
    b = mod(b*b, m); 
    p >>= 1LL;
  } 
  return ans;
}
 
////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e4+5;

int dp[N][105][2];
int n, d;
string s;

int solve(int i, int md, int edge){
	if(i == n) return md == 0;
	int& ans = dp[i][md][edge];
	if(ans != -1) return ans;
	int sum = 0;
	if(edge){
		for(int k = 0; k <= (s[i]-'0'); k++){
			sum = mod(sum + solve(i+1, mod(md+k, d), (k == (s[i]-'0'))), MOD);
		}
	}else{
		for(int k = 0; k <= 9; k++){
			sum = mod(sum + solve(i+1, mod(md+k, d), 0), MOD);
		}
	}
	return ans = sum;
}

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s >> d;
  n = len(s);
  memset(dp, -1, sizeof dp);
  cout << mod(solve(0, 0, 1)-1, MOD) << '\n';
  return 0; 
}