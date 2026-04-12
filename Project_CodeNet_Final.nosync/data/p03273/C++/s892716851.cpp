#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<int> hv(h), wv(w);
    rep(i,h) {
        int cnt = 0;
        rep(j,w) {
            if (s[i][j] == '#') cnt++;
        }
        if (cnt == 0) hv[i]++;
    }
    rep(j,w) {
        int cnt = 0;
        rep(i,h) {
            if (s[i][j] == '#') cnt++;
        }
        if (cnt == 0) wv[j]++;
    }
    rep(i,h){
        if (hv[i]) continue;
        rep(j,w) {
            if (wv[j]) continue;
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}