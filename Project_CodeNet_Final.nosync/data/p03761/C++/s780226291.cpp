#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

void solve(long long n, std::vector<std::string> S) {
    int cnt[128] = {};
    for(int i = 0 ; i < 128 ; i++) cnt[i] = 11451419;
    for (auto s : S) {
        int sub[128] = {};
        for (auto c : s) {
            sub[c]++;
        }
        for (int i = 0; i < 128; i++) {
            cnt[i] = min(cnt[i], sub[i]);
        }
    }
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << (char) i;
        }
    }
    cout << endl;
}

int main() {
    long long n;
    scanf("%lld", &n);
    std::vector<std::string> S(n);
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    }
    solve(n, std::move(S));
    return 0;
}
