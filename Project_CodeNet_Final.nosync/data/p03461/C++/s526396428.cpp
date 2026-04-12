#include <bits/stdc++.h>

#define VARNAME(x) #x
#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
vector<T> Vec(int n, T v)
{
    return vector<T>(n, v);
}
template <class... Args>
auto Vec(int n, Args... args)
{
    auto val = Vec(args...);
    return vector<decltype(val)>(n, move(val));
}
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
constexpr T INF = numeric_limits<T>::max() / 100;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B;
    cin >> A >> B;
    vector<vector<int>> d(A, vector<int>(B, 0));
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            cin >> d[i][j];
        }
    }
    constexpr int MAX = 100;
    vector<vector<int>> c(MAX + 1, vector<int>(MAX + 1, -1));
    int M = 0;
    constexpr int N = MAX + 1;
    for (int a = 0; a <= MAX; a++) {
        for (int b = 0; b <= MAX; b++) {
            for (int x = 1; x <= A; x++) {
                for (int y = 1; y <= B; y++) {
                    c[a][b] = max(c[a][b], d[x - 1][y - 1] - x * a - y * b);
                }
            }
            if (c[a][b] >= 0) {
                M++;
            }
        }
    }

    for (int a = 1; a <= A; a++) {
        for (int b = 1; b <= B; b++) {
            int mini = INF<int>;
            for (int i = 0; i <= MAX; i++) {
                for (int j = 0; j <= MAX; j++) {
                    mini = min(mini, a * i + b * j + c[i][j]);
                }
            }
            if (mini != d[a - 1][b - 1]) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }


    constexpr int S = 1;
    constexpr int T = 2 * MAX + 2;
    cout << "Possible" << endl;
    cout << T << " " << M + 2 * MAX << endl;
    for (int i = 0; i < MAX; i++) {
        cout << i + 1 << " " << i + 2 << " "
             << "X" << endl;
        cout << N + i + 1 << " " << N + i + 2 << " "
             << "Y" << endl;
    }
    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j <= MAX; j++) {
            if (c[i][j] >= 0) {
                cout << i + 1 << " " << 2 * MAX + 2 - j << " " << c[i][j] << endl;
            }
        }
    }
    cout << S << " " << T << endl;
    return 0;
}
