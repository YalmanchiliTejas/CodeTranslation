#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false)cerr
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> ii;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vii;
typedef long double ld;
typedef vector<ld> vld;
typedef vector<vector<ld>> vvld;
typedef vector<bool> vbl;
typedef vector<vbl> mbl;
#define ff first
#define ss second
#define pb emplace_back
#define mp make_pair
#define all(s) (s).begin(), (s).end()
#define minel(a) *min_element(all(a))
#define maxel(a) *max_element(all(a))
#define pq(t) priority_queue<t, vector <t>, greater <t>>
#define pqd(t) priority_queue<t>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))      // Used to iterate over the types

const ll mod = 1e9 + 7;
const ll mx = 1e18;
const ll inf = 1e7;

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// For printing variables and their respective values

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

auto mods() { return 0; }

template<typename T, typename... Args>
auto mods(T a, Args... args) { return (a + mods(args...) + mod) % mod; }

auto modp() { return 1; }

template<typename T, typename... Args>
auto modp(T a, Args... args) { return ( a * modp(args...) )% mod; }
// ! inputs should be positive and less than `mod`.

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// !Taking `int` input

template<typename T>
T nxt(){
    T x;
    cin >> x;
    return x;
}

//  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

inline void solve()
{
   int n = nxt<int>();
   if (n < 30)
    cout << "No\n";
    else
        cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}