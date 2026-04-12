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
    ll L;
    cin >> L;
    vector<string> S(2);
    cin >> S[0] >> S[1];
    auto comp = [](const string& s1, const string& s2) {
        return s1 + s2 < s2 + s1;
    };
    sort(S.begin(), S.end(), comp);
    const ll s = S[0].size();
    const ll t = S[1].size();
    for (ll l = L; l >= 0; l--) {
        const ll len = s * l;
        if (len <= L and (L - len) % t == 0) {
            const ll snum = l;
            const ll tnum = (L - len) / t;
            for (int i = 0; i < snum; i++) {
                cout << S[0];
            }
            for (int i = 0; i < tnum; i++) {
                cout << S[1];
            }
            cout << endl;
            return 0;
        }
    }


    return 0;
}
