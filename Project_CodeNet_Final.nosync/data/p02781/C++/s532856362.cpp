#include <bits/stdc++.h>

#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9+7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

int main(){
    string s;
    int n, k;

    cin >> s >> k;
    n = s.size();

    //dp[i][j][l] :上からi桁めでj個０でない桁がある個数(l=0 ちょうどn l=1 nより小さい)
    ll dp[120][5][2] = {};
    dp[0][0][0] = 1;

    rep(i, n){
        rep(j, k+1){
            //前の桁の引継ぎ
            dp[i+1][j][1] += dp[i][j][1];
            //既にnより小さいなら１〜９まで全て選べる
            dp[i+1][j+1][1] += dp[i][j][1]*9;
            //制約ちょうどの場合
            if(s[i] != '0'){
                //現在の桁を０にすればそのまま
                dp[i+1][j][1] += dp[i][j][0];
                //i桁の数-1個使うなら次の桁からnより小さくできる
                dp[i+1][j+1][1] += dp[i][j][0]*(s[i]-'1');
                //ギリギリで攻めて行く
                dp[i+1][j+1][0] += dp[i][j][0];
            } 
            else {
                dp[i+1][j][0] += dp[i][j][0];
            }
        }
    }

    cout << dp[n][k][0] + dp[n][k][1] << endl;
}