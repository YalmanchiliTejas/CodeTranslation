#include <bits/stdc++.h>

#define show(x) cout << #x << " = " << x << endl

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

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (decltype(n) i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n % 2 == 0) {
        for (int i = n - 1; i >= 0; i -= 2) {
            cout << a[i] << " ";
        }
        for (int i = 0; i < n; i += 2) {
            cout << a[i] << " ";
        }
    } else {
        for (int i = n - 1; i >= 0; i -= 2) {
            cout << a[i] << " ";
        }
        for (int i = 1; i < n; i += 2) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
