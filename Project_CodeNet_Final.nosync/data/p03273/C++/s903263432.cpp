#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD (long long)1e9+7
#define LINF (long long)4e18

int main(){
    int H,W; cin >> H >> W;
    vector<vector<char>> a(H,vector<char>(W));
    rep(i,H)rep(j,W) cin >> a[i][j];

    vector<bool> gyou(H,false);
    vector<bool> retu(W,false);

    rep(i,H){
        rep(j,W){
            if(a[i][j] == '#') gyou[i] = true;
        }
    }
    rep(i,W){
        rep(j,H){
            if(a[j][i] == '#') retu[i] = true;
        }
    }
    rep(i,H){
        rep(j,W){
            if(gyou[i] && retu[j]) cout << a[i][j];
        }
        cout << endl;
    }
}
   