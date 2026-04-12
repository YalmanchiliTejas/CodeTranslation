#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<v> vv;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
const ll MOD = 1e9 + 7;
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yesno(f) \
    if (f)       \
        yes else no;
#define noo \
    { no return; }
#define amax(x, y) \
    if (y > x)     \
        x = y;
#define amin(x, y) \
    if (y < x)     \
        x = y;
#define sz(x) (ll) x.size()
#define sq(x) ((x) * (x))

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

template<typename T = ll>
vector<T> ga(ll n, bool oneIndexed = false) {
    vector<T> a = vector<T>(n + oneIndexed);

    for (ll i = 0; i < n; i++) {
        T p;
        cin >> p;
        a[i + oneIndexed] = p;
    }

    return move(a);
}

template<typename T, typename A>
void pa(vector<T, A> const &a, ll begin = 0, ll end = -1) {
    if (end == -1)
        end = sz(a) - 1;
    for (ll i = begin; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

ll ceil(ll x, ll y) {
    return (x + y - 1) / y;
}

void solve() {
    ll n;
    cin >> n;
    v a = ga(n);


//    priority_queue<ll, v, less<>> pq;

//    for (auto x : a)pq.push(x);

    ll c = 0;

    ll target = n - 1;
//    while (!pq.empty()) {
//        auto num = pq.top();
//        pq.pop();
//        if (num <= target)continue;
//
//        ll steps = ceil(num - target, n);
//        c += steps;
//        num -= steps * n;
//    }

    while (true) {
        sort(rall(a));
        if (a.front() <= target)break;

        ll num = a.front();
        ll steps = ceil(num - target, n);
        c += steps;
        a[0] -= steps * n;
        for (ll i = 1; i < n; i++)a[i] += steps;
    }
    cout << c << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}