#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

void header() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void solve() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'A') a++;
        else b++;
    }
    cout << ((a == 0 || b == 0) ? "No" : "Yes") << endl;
}

int main() {
	header();
	solve();
	return 0;
}
