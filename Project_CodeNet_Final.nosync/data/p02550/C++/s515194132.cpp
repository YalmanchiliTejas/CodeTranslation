#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define endl '\n'

int mod = 998244353;

int pw(int a, int k) {
    if (k == 0) return 1;
    if (k % 2) return ((long long) pw(a, k - 1) * a) % mod;
    int t = pw(a, k / 2);
    return ((long long) t * t) % mod;
}

int rv(int a) {
    return pw(a, mod - 2);
}

int ml(int a, int b) {
    return ((long long)a * b) % mod;
}

int ml(int a, int b, int c) {
    return ml(ml(a, b), c);
}

int dv(int a, int b) {
    return ml(a, rv(b));
}

int sm(int a, int b) {
    return (a + b) % mod;
}

int df(int a, int b) {
    return ((long long)a + mod - b) % mod;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string yy = "Yes\n";
string nn = "No\n";
string imp = "IMPOSSIBLE\n";



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1; // cin >> t;
    while (t--) {
        int n; cin >> n;
        int x, m; cin >> x >> m;
        unordered_map<int, int> mp;
        int cnt = 0;
        vector<int> a(m + 1);
        vector<int> b(m + 2);
        a[0] = x;
        b[1] = x;
        mp[x] = 1;
        int cur = 1;
        int st = -1;
        while (true) {
            a[cur] = (a[cur - 1] * a[cur - 1]) % m;
            b[cur + 1] = (a[cur] + b[cur]);
            if (mp[a[cur]]) {
                st = mp[a[cur]];
                break;
            }
            mp[a[cur]] = cur+1;
            cur++;
        }
        int step = cur + 1 - st;
        int val = b[cur + 1] - b[st];
        int beg = b[st];
        if (n <= st) {
            cout << b[n] << endl;
            continue;
        }
        n -= st;
        beg += (n / step) * val;
        n %= step;
        beg += b[st + n] - b[st];
        cout << beg << endl;


    }
    return 0;
}
