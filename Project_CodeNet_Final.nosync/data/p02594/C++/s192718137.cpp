#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()
#define ll long long
#define all(_v) _v.begin(), _v.end()
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pvllvll pair <vector <ll>, vector <ll> >
#define ld long double
#define veci vector <int>
#define vecll vector <ll>

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const double PI = 3.1415926535897932384626433832795;
const double eps = 1e-9;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;

void solve() {
    int x;
    cin >> x;
    if(x >= 30) cout << "Yes";
    else cout << "No";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
    ///cin >> t;
    while(t--) solve(), cout << '\n';
    return 0;
}
