#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define all(x) x.begin(),x.end()
ll dp[105][5][2]; //桁 0以外 確定 == 1
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;int k,n;
    cin >> s; n = s.size();
    cin >> k;
    dp[0][0][0] = 1;
    rep(m,0,2){
        rep(i,0,4){
            rep(j,0,n){
                rep(d,0,10){
                    int ui = i,uj = j+1,um = m;
                    if(d != 0) ui++;
                    if(m == 0 && d > s[j]-'0') continue;
                    if(d < s[j]-'0') um =1;
                    dp[uj][ui][um] += dp[j][i][m];
                }
            }                
        }
    }
    cout << dp[n][k][0] + dp[n][k][1] << endl;

}