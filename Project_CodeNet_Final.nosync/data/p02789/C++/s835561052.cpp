#pragma GCC optimize "O3"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define POP pop_back
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define F first
#define S second
#define X real()
#define Y imag()
#ifndef LOCAL
    #define endl "\n"
#endif

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef long long C;
typedef complex<C> P;

const int INF = 1e9;
const long long LLINF = 1e18;
const double PI = 3.14159265358979323;
const long long PRIME = (1ll << 31) - 1;
const long long PRIME2 = 269;
const long long MOD = 1e9 + 7;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class U> using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using hash_set = gp_hash_table<T, null_type>;
template <class T, class U> using hash_map = gp_hash_table<T, U>;
template <class T, class U> ostream& operator<< (ostream &out, pair<T, U> p) { return out << "(" << p.F << ", " << p.S << ")"; }
template <class T> ostream& operator<< (ostream &out, vector<T> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T> ostream& operator<< (ostream &out, set<T> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T, class U> ostream& operator<< (ostream &out, map<T, U> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T> ostream& operator<< (ostream &out, ordered_set<T> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T, class U> ostream& operator<< (ostream &out, ordered_map<T, U> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T> ostream& operator<< (ostream &out, hash_set<T> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T, class U> ostream& operator<< (ostream &out, hash_map<T, U> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T> int sign (T x) { return (x > 0) - (x < 0); }
inline ll mod (ll a, ll b) { return a%b + (a < 0) * b; }
inline ll mod (ll a) { return mod(a, MOD); }
C dot (P a, P b) { return a.X * b.X + a.Y * b.Y; }
C cross (P a, P b) { return a.X * b.Y - b.X * a.Y; }

double startTime;
double currTime() { return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count() / 1e9; }
double execTime() { return currTime() - startTime; }

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    srand(time(0));
    startTime = currTime();

    int n, m;
    cin >> n >> m;
    cout << (n == m ? "Yes" : "No") << endl;
}