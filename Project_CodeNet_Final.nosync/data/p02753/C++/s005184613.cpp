#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define sc3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sc4(x, y, z, t) scanf("%d%d%d%d", &x, &y, &z, &t)
#define print(x) printf("%d ", x)
#define println(x) printf("%d\n", x)
#define println2(x, y) printf("%d %d\n", x, y)
#define println3(x, y, z) printf("%d %d %d\n", x, y, z)
#define println4(x, y, z, t) printf("%d %d %d %d\n", x, y, z, t)
#define mp make_pair
#define pb push_back
#define ft first
#define sd second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define endl '\n'                           // CommentInInteractive
#define DB(x) cerr << #x << " = " << x << endl

const ld eps = 1e-6;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;

void solve() {
    string s;
    cin >> s;
    if (s == "AAA" || s == "BBB") cout << "No" << endl;
    else cout << "Yes" << endl;
}

//#define FILES
//#define TIME

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef FILES
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    auto start = chrono::high_resolution_clock::now();
    solve();
    auto stop = chrono::high_resolution_clock::now();

#ifdef TIME
    cerr << chrono::duration_cast <chrono::milliseconds> (stop - start).count() << " ms\n";
#endif
    return 0;
}