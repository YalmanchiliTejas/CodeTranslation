#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long
#define mkpr make_pair
#define REP(i,a,b) for (i = a; i <= b; i++)
#define RREP(i,a,b) for (int i = a; i >= b; i--)

typedef pair<int, int> pii;
typedef map<int, int> mpii;
typedef unordered_map<int, int> umpii;
typedef vector<int> vi;
typedef vector<pii> vpii;
#define ff first
#define ss second
#define setbits(x)  __builtin_popcountll(x)
#define zrobits(x)  __builtin_ctzll(x)
#define precise(x) cout<<fixed<<setprecision(9)<<x<<endl
#define mod 1000000007
#define MAX 200010
#define INF (long long) 4e18
#define endl "\n"

void in() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int32_t main() {
	in();
	int n;
	cin >> n;
	if (n >= 30)
		cout << "Yes\n";
	else
		cout << "No\n";

}