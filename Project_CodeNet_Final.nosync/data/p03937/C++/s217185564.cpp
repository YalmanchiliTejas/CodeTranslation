#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    int x = 0;
    int y = 0;

    while(1){
        int cnt = 0;
        int togo;
        rep(d, 4){
            int dx = x + di[d];
            int dy = y + dj[d];

            if(dx<0 || dx>=w || dy<0 || dy>=h) continue;
            if(a[dy][dx] == '#') {
                ++cnt;
                togo = d;
            }
        }
        if(cnt>1 || (cnt==1) && (togo==2 || togo==3)){
            puts("Impossible");
            return 0;
        }
        else{
            a[y][x] = '.';
            x = x + di[togo];
            y = y + dj[togo];
        }
        // cout << x << " " << y << endl;
        // rep(i, h) cout << a[i] << endl;
        // return 0;
        if(x==w-1 && y==h-1) break;
    }

    rep(d, 4){
        int dx = x + di[d];
        int dy = y + dj[d];

        if(dx<0 || dx>=w || dy<0 || dy>=h) continue;
        if(a[dy][dx] == '#') {
            puts("Impossible");
            return 0;
        }
    }

    puts("Possible");

    return 0;
}