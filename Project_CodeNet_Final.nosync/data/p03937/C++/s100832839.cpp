//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) {
        cin >> s[i];
    }

    int c = 0;
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') {
                ++c;
            }
        }
    }

    cout << (c == h+w-1 ? "Possible":"Impossible") << endl;
}