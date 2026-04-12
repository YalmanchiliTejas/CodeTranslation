#include <bits/stdc++.h>

#define VARNAME(x) #x
#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "sz:" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    for (auto& e : v) {
        is >> e;
    }
    return is;
}

template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}


constexpr ll MOD = (ll)1e9 + 7LL;

template <typename T>
constexpr T INF = numeric_limits<T>::max() / 10;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll K, A, B;
    cin >> K >> A >> B;
    cout << ((K <= A) ? 1 : (A - B) > 0 ? 1 + (K - B - 1) / (A - B) * 2 : -1) << endl;
    return 0;
}
