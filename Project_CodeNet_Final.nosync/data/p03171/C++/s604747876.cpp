#include<bits/stdc++.h>
using namespace std;
#define fast                         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int                          long long int
#define double                       long double
#define ff                           first
#define ss                           second
#define pb                           push_back
#define eb                           emplace_back
#define all(x)                       (x).begin(), (x).end()
#define sz(x)                        ((int)(x).size())
#define len(x)                       ((int)(x).length())
#define pii                          pair<int,int>
#define vi                            vector<int>
#define vd                           vector<double>
#define vs                            vector<string>
#define mp                          map<int,int>
#define ms(x,y)                     memset(x,y,sizeof(x))
#define ump                         unordered_map<int,int>

#define lb                            lower_bound
#define ub                            upper_bound
#define nx                            cout<<"\n";
#define inf                           9223372036854775807
#define PI                            3.14159265

const int MOD = 1e9 + 7;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }
inline int add(int a, int b) {    return ((a % MOD) + (b % MOD)) % MOD;}

inline int multi(int a, int b) {   return ((a % MOD) * (b % MOD)) % MOD;}

inline int sub(int a, int b) {       a %= MOD; b %= MOD; a -= b; if (a < 0) a += MOD; return a;}

inline int power(int a, int b) {       a %= MOD; int res = 1; while (b > 0) {if (b & 1) {res = multi(res, a);} a = multi(a, a); b >>= 1;}  return res;}

bool isPrime(int  x) {      if (x <= 4 || x % 2 == 0 || x % 3 == 0) {return x == 2 || x == 3;} for (int i = 5; i * i <= x; i += 6) {if (x % i == 0 || x % (i + 2) == 0) { return 0;}} return 1;}

int dp[3001][3001];
int arr[3001];
int solve(int i, int j)
{
    if (dp[i][j] != -1)return dp[i][j];
    if (i == j)return arr[i];

    int ans = max(arr[i] - solve(i + 1, j), arr[j] - solve(i, j - 1));
    return dp[i][j] = ans;
}
int32_t main()
{

    int n; cin >> n;

    for (int i = 0; i < n; i++)cin >> arr[i];
    ms(dp, -1);
    int ans = solve(0, n - 1);
    cout << ans << endl;

}

