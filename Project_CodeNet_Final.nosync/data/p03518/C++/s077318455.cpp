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

int N;
void query(vector<int>& p, const int k, vector<int>& op)
{
    op.push_back(k);
    for (int i = k; i < N; i++) {
        swap(p[i], p[i - k]);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    vector<int> op;
    for (int i = 0; i < 2 * N * N; i++) {
        if (p[0] > 0 and p[N - 1] > 0 and p[0] < p[N - 1]) {
            query(p, N - 1, op);
        }
        query(p, 1, op);
    }
    while (p[0] > 0) {
        query(p, 1, op);
    }

    cout << op.size() << endl;
    for (const int o : op) {
        cout << o << endl;
    }
    show(p);

    return 0;
}
