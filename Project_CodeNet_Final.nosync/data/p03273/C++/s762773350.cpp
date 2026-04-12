#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
using LP = pair<ll,ll>;
using P = pair<ll,int>;
ll inf = 1e18;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    vector<bool> check_h(h,false), check_w(w,false);
    rep(i, h) {
        bool flag = true;
        rep(j, w){
            if(g[i][j] == '#') {
                flag = false;
                break;
            }
        }
        if (flag) check_h[i] = flag; 
    }
    rep(i, w) {
        bool flag =true;
        rep(j, h){
            if(g[j][i] == '#') {
                flag = false;
                break;
            }
        }
        if (flag) check_w[i] = flag; 
    }
    rep(i, h){
        if (check_h[i]) continue;
        rep(j, w){
            if (check_w[j]) continue;
            cout << g[i][j];

        }
        cout << endl;
    }


}