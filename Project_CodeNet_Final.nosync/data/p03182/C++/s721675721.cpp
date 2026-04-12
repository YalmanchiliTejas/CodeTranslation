#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forlr(i, l, r) for (int i = int(l); i <= int(r); i++)
#define repeat(n) for (int hjfjke = 0; hjfjke < int(n); hjfjke++)
#define all(c) c.begin(), c.end()
#define ll long long

int mod = 1000000007;

inline int add(int a, int b);
inline int mult(int a, int b);
inline int sub(int a, int b);

int l[200500];
int r[200500];
int a[200500];

long long mx[800500];
long long ad[800500];

void add(int v, int l, int r, int a, int b, long long c) {
    if (r <= a || b <= l)
        return;

    if (a <= l && r <= b) {
        ad[v] += c;
        mx[v] += c;
        return;
    }

    int m = (l + r) >> 1;

    add(v + v + 1, l, m, a, b, c);
    add(v + v + 2, m, r, a, b, c);

    mx[v] = max(mx[v + v + 1], mx[v + v + 2]) + ad[v];
}

long long get(int v, int l, int r, int a, int b) {
    if (r <= a || b <= l)
        return -1e18;

    if (a <= l && r <= b) {
        return mx[v];
    }

    int m = (l + r) >> 1;
    return max(get(v + v + 1, l, m, a, b), get(v + v + 2, m, r, a ,b));
}


int32_t main() {
    std::iostream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int n, m;
    cin >> n >> m;

    forn(i, m) cin >> l[i] >> r[i] >> a[i];

    vector<pair<int, int>> evs;

    forn(i, m) {
        evs.emplace_back(l[i], -i - 1);
        evs.emplace_back(r[i], i + 1);
    }

    forlr(i, 1, n)
     evs.emplace_back(i, 0);

    sort(evs.begin(), evs.end());

    long long ans = 0;

    for (auto p : evs) {
        if (p.second == 0) {
            long long sum = get(0, 0, n + 1, 0, p.first);
            ans = max(ans, sum);
            add(0, 0, n + 1, p.first, p.first + 1, sum);

            //cout << sum << endl;
        } else if (p.second > 0) {
            int id = p.second - 1;
            add(0, 0, n + 1, 0, l[id], -a[id]);
        } else {
            int id = -p.second - 1;
            add(0, 0, n + 1, 0, l[id], a[id]);
        }
    }

    cout << ans;

    return 0;
}

int add(int a, int b) {
    int result = a + b;
    if (result >= mod)
        result -= mod;
    return result;
}

int sub(int a, int b) {
    int result = a - b;
    if (result < 0)
        result += mod;
    return result;
}

int mult(int a, int b) {
    return (a * 1ll * b) % mod;
}