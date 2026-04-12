#include<bits/stdc++.h>
using namespace std;

#define Ff(i,a,b) for(i=a;i<b;i++)
#define Fb(i,a,b) for(i=a-1;i>=b;i--)
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define mp make_pair
#define PI 2*asin(1)
#define all(x) x.begin(),x.end()
#define trav(x) for(auto& i:x)
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define spc ' '

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef map<int, int> mi;
typedef map<long long, long long> mll;
typedef unordered_map<int, int> umi;
typedef unordered_map<long long, long long> umll;
typedef set<int> si;
typedef set<long long> sll;
typedef unordered_set<int> usi;
typedef unordered_set<long long> usll;

const ll N = 1e9 + 7;
#define int long long

void sub() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
}


void solve() {
	int n;
	cin >> n;
	int a[n];
	int i, j;
	int s = 0;
	Ff(i, 0, n)
	cin >> a[i];
	int g = 0;
	Ff(i, 0, n)
	g += a[i];
	Ff(i, 0, n - 1) {
		s = (s + (a[i] % N) * ((g - a[i]) % N)) % N;
		g -= a[i];
	}
	cout << s << endl;
}



int32_t main() {
	FIO
	sub();
	int t = 1;
	// cin >> t;
	while (t--)
		solve();

	return 0;
}


