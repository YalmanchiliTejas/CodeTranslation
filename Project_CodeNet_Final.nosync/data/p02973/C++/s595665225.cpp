#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const int INF = numeric_limits<int>::max();
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    int n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vi maxi;
    maxi.push_back(a[0]);
    int colors = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > maxi[0])
            maxi[0] = a[i];
        else if (a[i] <= maxi.back()) {
            colors++;
            maxi.push_back(a[i]);
        } else {
            int ng = 0;
            int ok = maxi.size() - 1;
            while (ng + 1 != ok) {
                int mid = (ng + ok) / 2;
                if (maxi[mid] < a[i])
                    ok = mid;
                else
                    ng = mid;
            }
            maxi[ok] = a[i];
        }
    }
    cout << colors << "\n";

    return 0;
}