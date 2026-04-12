#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int inf = 1e9 + 5;
const ll inf64 = 1e18 + 5;

const int MAX = 1e4 + 5;
const int N = 105;
int dp[MAX][N][2], d;
vector <int> v;

int rec(int pos, int sum, bool f)
{
	if(pos == v.size()) return (sum == 0);
	int &res = dp[pos][sum][f];
	if(~res) return res;
	
	int lim = (f ? 9 : v[pos]);
	res = 0;
	
	for(int i = 0; i <= lim; i++) {
		int nsum = (sum + i) % d;
		res += rec(pos + 1, nsum, f || (i < v[pos]));
		res %= MOD;
	}
	return res;
}
int main()
{
	boost;
	string s;
	cin >> s;
	cin >> d;
	
	for(char c : s)
	v.pb(c - '0');
	
	memset(dp, -1, sizeof dp);
	cout << (rec(0, 0, 0) - 1 + MOD) % MOD;
}
