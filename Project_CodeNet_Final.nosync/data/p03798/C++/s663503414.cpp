#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int INF = 2e18;

signed main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<string> startStr = {"SS", "SW", "WS", "WW"};
    for (string start : startStr) {
        string save = start;
        for (int i = 1; i < N - 1; i++) {
            if (save[i] == 'S') {
                if (S[i] == 'o') {
                    save += save[i - 1];
                } else {
                    save += (save[i - 1] == 'S' ? 'W' : 'S');
                }
            } else {
                if (S[i] == 'x') {
                    save += save[i - 1];
                } else {
                    save += (save[i - 1] == 'S' ? 'W' : 'S');
                }
            }
        }
        auto check = [&](int idx) {
            int left = (idx - 1 + N) % N;
            int right = (idx + 1 + N) % N;
            if (save[idx] == 'S') {
                if (S[idx] == 'o') {
                    if (save[left] != save[right]) return false;
                } else {
                    if (save[left] == save[right]) return false;
                }
            } else {
                if (S[idx] == 'x') {
                    if (save[left] != save[right]) return false;
                } else {
                    if (save[left] == save[right]) return false;
                }
            }
            return true;
        };
        if (check(0) && check(N - 1)) {
            cout << save.substr(0, N) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
