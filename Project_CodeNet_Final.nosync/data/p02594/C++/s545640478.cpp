#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef pair<int, int> ii;
typedef pair<i64, i64> ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#define fastIO() ios_base::sync_with_stdio(0), cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ms(a, x) memset(a, x, sizeof(a))
#define len(x) (x).size()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 1e9;
const int maxn = 2e5+5;
const int mod = 1e9+7;

int main() {
    fastIO();
    int x; cin >> x;
    cout << (x>=30?"Yes\n":"No\n");
    return 0;
}

