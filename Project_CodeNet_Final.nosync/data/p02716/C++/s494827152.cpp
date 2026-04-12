#include "vector"
#include "set"
#include "map"
#include "unordered_map"
#include "string"
#include "iostream"
#include "algorithm"
#include "queue"

using namespace std;

#define ll long long
#define INF 2e9
#define MOD 998244353

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;


template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    bool first = true;
    for (const auto& j: v) {
        if (!first) {
            os << " ";
        }
        first = false;
        os <<j;
    }
    return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& elem : v) {
        is >> elem;
    }
    return is;
}

vector<vi> g;
vi p;
vi h;
void dfs(int x, int prev) {
    p[x] = prev;
    h[x] = (prev == -1) ? 0 : h[prev] + 1;

    for (int y : g[x]) {
        if (y != prev) {
            dfs(y, x);
        }
    }
}

struct v {
    int a;
    int b;
    int c;
};

bool comp(const v& x, const v& y) {
    return x.c < y.c;
}

void solve() {
    int n;
    cin >> n;
    vll a(n);
    cin >> a;

    vll bef0(n+1, 0);
    vll bef1(n+1, 0);
    vll aft0(n+1, 0);
    vll aft1(n+1, 0);

    bef0[0] = a[0];
    for (int i=1; i<n; i++) {
        bef0[i] = bef0[i-1];
        bef1[i] = bef1[i-1];
        if (i % 2) {
            bef1[i] += a[i];
        } else {
            bef0[i] += a[i];
        }
    }
    for (int i=n-1; i>=0; i--) {
        aft0[i] = aft0[i+1];
        aft1[i] = aft1[i+1];
        if (i % 2) {
            aft1[i] += a[i];
        } else {
            aft0[i] += a[i];
        }
    }


    if (n % 2 == 0) {
        ll ma = max(aft0[0], aft1[0]);
        for (int i = 1; i < n-2; i++) {
            if (i % 2 ==  1) {
                ma = max(ma, bef0[i-1] + aft1[i+2]);
            }
        }
        cout << ma;
        return;
    }


    ll ma = max(aft0[2], aft1[1]);
    for (int i = 1; i < n-1; i++) {
        if (i % 2 == 0) {
            ma = max(ma, bef0[i-1] + aft0[i+2]);
            ma = max(ma, bef1[i-1] + aft0[i+2]);
        } else {
            ma = max(ma, bef0[i-1] + aft1[i+2]);
            ma = max(ma, bef0[i-1] + aft0[i+2]);
        }
    }

    for (int i = 1; i < n-2; i++) {
        if (i % 2 == 1) {
            ma = max(ma, bef0[i-1] + aft0[i+3]);
        }
    }

    ll cur0 = a[0];
    ll cur1 = a[0];
    for (int i = 3; i < n-1; i++) {
        if (i % 2 == 0) {
            ma = max(ma, cur0 + aft0[i+2]);
            cur0 = cur1;
        } else {
            cur0 += a[i];
            cur1 = max(cur1 + a[i], bef0[i-1]);
        }

        //cout << i << ' ' << cur0 << ' ' << cur1 << ' ' << ma << endl;
    }

    cout << ma;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    if (0) {
        int tests;
        cin >> tests;
        while (tests--) {
            solve();
            cout << "\n";
        }
    } else {
        solve();
        cout << endl;
    }

    return 0;
}