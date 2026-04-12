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
        vector<char> save = {start[0], start[1]};
        for (int i = 1; i < N - 1; i++) {
            if (save[i] == 'S') {
                if (S[i] == 'o') {
                    save.push_back(save[i - 1]);
                } else {
                    save.push_back(save[i - 1] == 'S' ? 'W' : 'S');
                }
            } else {
                if (S[i] == 'x') {
                    save.push_back(save[i - 1]);
                } else {
                    save.push_back(save[i - 1] == 'S' ? 'W' : 'S');
                }
            }
        }
        bool check = true;
        for (int i = 0; i < N; i++) {
            int left = (i - 1 + N) % N;
            int right = (i + 1 + N) % N;
            if (save[i] == 'S') {
                if (S[i] == 'o') {
                    if (save[left] != save[right]) check = false;
                } else {
                    if (save[left] == save[right]) check = false;
                }
            } else {
                if (S[i] == 'x') {
                    if (save[left] != save[right]) check = false;
                } else {
                    if (save[left] == save[right]) check = false;
                }
            }
        }
        if (check) {
            for (int i = 0; i < N; i++) cout << save[i];
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
