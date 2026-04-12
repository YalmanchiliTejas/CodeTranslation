#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

char reverse(char hoge) {
    if(hoge == 'S') {
        return 'W';
    } else {
        return 'S';
    }
}
int main() {
    int N;
    string s;
    cin >> N;
    cin >> s;
    //ちょうどなりが同じか違う
    string sw = "SW";
    for(char &i : sw) {
        for(char &j : sw) {
            string res = {i, j};
            // cout << res << endl;
            for(int l = 1; l < N - 1; l++) {
                if(res[l] == 'S') {
                    //ただしい
                    if(s[l] == 'o') {
                        res += res[l - 1];
                    } else {
                        res += reverse(res[l - 1]);
                    }

                } else {
                    if(s[l] == 'x') {
                        res += res[l - 1];
                    } else {
                        res += reverse(res[l - 1]);
                    }
                }
            }
            if(res[N - 1] == 'S') {
                // Sheep
                if(s[N - 1] == 'x') {
                    if(res[0] == res[N - 2]) {
                        continue;
                    }
                } else {
                    if(res[0] != res[N - 2]) {
                        continue;
                    }
                }
            } else {
                // Wolfe
                if(s[N - 1] == 'o') {
                    if(res[0] == res[N - 2]) {
                        continue;
                    }
                } else {
                    if(res[0] != res[N - 2]) {
                        continue;
                    }
                }
            }
            if(i == 'S') {
                if(s[0] == 'x') {
                    if(res[N - 1] != res[1]) {
                        cout << res << endl;
                        return 0;
                    }
                } else {
                    if(res[N - 1] == res[1]) {
                        cout << res << endl;
                        return 0;
                    }
                }
            } else {
                if(s[0] == 'x') {
                    if(res[N - 1] == res[1]) {
                        cout << res << endl;
                        return 0;
                    }
                } else {
                    if(res[N - 1] != res[1]) {
                        cout << res << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}