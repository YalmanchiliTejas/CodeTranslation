    #include <bits/stdc++.h>
    
    using namespace std;
    
    using ll = long long;
    using ld = long double;
    using vi = vector<int>;
    using vvi = vector<vi>;
    using pii = pair<int, int>;
    using vpi = vector<pii>;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n;
        cin >> n;
        vi a(n);
        for (int &x : a) cin >> x;
        ll res = 0, cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            res += cur * a[i];
            res %= (ll)1e9+7;
            cur += a[i];
            cur %= (ll)1e9+7;
        }
        cout << res << "\n";

        return 0;
    }