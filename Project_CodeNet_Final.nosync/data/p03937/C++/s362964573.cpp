#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> a(H);
    rep(i, 0, H) cin >> a[i];

    ll h = 0, w = 0;
    ll d1[2] = {1,0}, d2[2] = {0,1};
    ll th, tw;
    vector<vector<bool>> s(H, vector<bool>(W, false));
    s[0][0] = true;
    while(true){
        ll c = 0;
        rep(i, 0, 2){
            ll nh = h+d1[i];
            ll nw = w+d2[i];
            if(nh < H && nw < W && a[nh][nw] == '#'){
            s[nh][nw] = true;
                c++;
                th = nh; tw = nw;
            }
        }
        if(c != 1){
            cout << "Impossible" << endl;
            return 0;
        }
        if(th == H-1 && tw == W-1) break;
        h = th; w = tw;
    }

    rep(i, 0, H){
        rep(j, 0, W){
            if(!s[i][j] && a[i][j] == '#'){
            cout << "Impossible" << endl;
            return 0;

            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}