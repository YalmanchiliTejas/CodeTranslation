#ifdef DEBUG

#else

#    pragma GCC optimize("O3,no-stack-protector")
#    pragma GCC optimize("unroll-loops")

#    if __cplusplus < 201703L
#        pragma GCC target("avx")
#    else
#        pragma GCC target("avx2")
#    endif

#endif

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;
typedef long double Ld;

using namespace std;
using Graph = vector<vector<Int>>;

const Ld pi = M_PI;
const Int MOD = 1000000007;
const Int INF = 1LL << 61;

Int Floor(Int a, Int b) {
    return (a - (a % b)) / b;
}

Int Ceil(Int a, Int b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return Floor(a, b) + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int alp = (int)('z' - 'a' + 1);
    int n;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(alp));
    for (int i = 0; i < n; i++) {
        string k;
        cin >> k;

        int ro = k.size();
        for (int j = 0; j < ro; j++) {
            s[i][k[j] - 'a']++;
        }
    }

    vector<int> anschars(alp, 1 << 30);
    for (int i = 0; i < alp; i++) {
        for (int j = 0; j < n; j++) {
            anschars[i] = min(anschars[i], s[j][i]);
        }
    }

    string ans;
    for (int i = 0; i < alp; i++) {
        int ro = anschars[i];
        for (int j = 0; j < ro; j++) {
            ans += (char)(i + 'a');
        }
    }

    cout << ans << endl;

    return 0;
}