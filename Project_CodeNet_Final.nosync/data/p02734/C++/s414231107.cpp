#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define st first
#define nd second                   
#define fori(i, a, b, c) 	for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define ford(i, a, b, c) 	for (int i = (int)(a); i >= (int)(b); i -= (int)(c))
#define MOD 998244353

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef long long lol;
typedef vector<lol> vlol;

ifstream in ("input");

const int NR = 3e3 + 5;

int n, S;
lol dp [NR];
lol ans;

int main()	{
	int i;
	int x;
	ios::sync_with_stdio(false);
	cin >> n >> S;
	fori(i, 1, n, 1) {
		cin >> x;
		if ( x > S )	continue;
		if ( x == S )	{
			( ans += i * (n-i+1) ) %= MOD;
			continue;
		}
		if ( dp [S - x] )	{
			(ans += dp [S-x]*(n-i+1) ) %= MOD ;
		} 
		ford(j, S-1, x+1, 1)	{
			( dp [j] += dp [j - x] ) %= MOD;
		}
		( dp[x] += i ) %= MOD;
	}			
	cout << ans;		
}