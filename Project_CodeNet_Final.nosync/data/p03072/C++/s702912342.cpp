//it was hard to write
//so it should be hard to read
#include <bits/stdc++.h>
#define sz size
#define pb push_back
#define ll long long
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define last(x) (x).size() - 1
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef double ld;

const int MAXN = 1e5 + 5;
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const double EPS = 1e-9;

int n, h[25], mx, res;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        if (mx <= h[i]) res++;
        mx = max(mx, h[i]);
    }
    cout << res;
    return 0;
}
