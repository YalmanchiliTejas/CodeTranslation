#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define all(x) x.begin(),x.end()

ll dp[105][4][2]; //i桁目, 0以外の数, Nより小さい確定のとき=0

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string n;
    ll k;
    cin >> n;
    cin >> k;
    dp[0][0][0] = 1;
    
    rep(i,0,n.size()) rep(j,0,4) rep(m,0,2){
        int nd = n[i] - '0';
        rep(d,0,10){
            int ni = i+1 ,nj = j,nm = m;
            if(d != 0) nj++;
            if(nj > k) continue;
            if(m == 0){
                if(d > nd) continue;
                if(d < nd) nm = 1;
            }
            dp[ni][nj][nm] += dp[i][j][m];
        }
    }
    cout << dp[n.size()][k][0] + dp[n.size()][k][1] << endl;
}