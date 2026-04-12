#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr long long INFL = numeric_limits<long long>::max() / 2;
constexpr int MOD = 1000000007;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H,M;
    cin >> H >> M;
    char a[H][M];
    rep(i,H){
        rep(j,M){
            cin >> a[i][j];
        }
    }
    bool z[H]={},z1[M]={};
    rep(i,H){
        rep(j,M){
            if(a[i][j]=='#') {
                z[i]=true;
                z1[j]=true; 
            }
        }
    }
    rep(i,H){
        if(z[i]){
            rep(j,M){
                if(z1[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }


}
