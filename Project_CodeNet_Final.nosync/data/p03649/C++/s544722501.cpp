#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();

signed main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    cin >> a;
    auto check = [&]() {
        bool temp = true;
        for (auto now : a) if (now > N - 1) temp = false;
        return temp;
    };
    ll ans = 0;
    while (true) {
        ll sum = 0;
        vector<ll> count(N, 0);
        for (int i = 0; i < N; i++) {
            if (a[i] <= N - 1) continue;
            ll minus = a[i] / N;
            sum += minus;
            count[i] = minus;
            a[i] %= N;
        }
        ans += sum;
        for (int i = 0; i < N; i++) {
            a[i] += sum - count[i];
        }
        if (check()) break;
    }
    cout << ans << endl;
}
