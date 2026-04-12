#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;
#define int long long
#define test int t; cin >> t; while (t--)
#define deb(x) cerr << #x << " " << x << endl;
#define debb(x, y) cerr << #x << " = " << x << "," << #y << " = " << y << endl <<endl;
#define pb push_back
#define pp pop_back
#define mkp make_pair 
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define MAX 50000

typedef long double ld;
const int N = 1e5 + 10;
const int maxn = 2e6 + 10;
const long double Pie = acos(-1);
 
signed main() {
    int n;
	cin >> n;
	
	if (n >= 30)	cout << "Yes";
	else            cout << "No";
	cout << "\n";
    return 0;
}
