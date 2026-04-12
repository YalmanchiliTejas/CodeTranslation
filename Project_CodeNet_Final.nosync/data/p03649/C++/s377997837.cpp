#include <bits/stdc++.h>

#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "sz=" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}

template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}


constexpr ll MOD = 1e9 + 7;

template <typename T>
constexpr T INF = numeric_limits<T>::max() / 100;

ll N;
vector<ll> a;

int main()
{
    cin >> N;
    a.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll total = 0;
    while (true) {
        ll sum = 0;
        for (ll i = 0; i < N; i++) {
            sum += a[i] / N;
            for (ll j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                a[j] += a[i] / N;
            }
            a[i] = a[i] % N;
        }
        total += sum;
        if (sum == 0) {
            break;
        }
    }
    cout << total << endl;

    return 0;
}
