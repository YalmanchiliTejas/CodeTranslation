#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 10100;
const int maxd = 110;
const ll modd = 1LL * 1e9 + 7;
ll dp[maxn][maxd][2][2];
string x;
ll d;

void solve() {

    dp[0][0][1][1] = 1LL;
    for(int len=0;len<x.length();len++) {
        for(int mod=0;mod<d;mod++) {
            for(int limit=0;limit<2;limit++) {
                for(int leading=0;leading<2;leading++) {
                    if(dp[len][mod][limit][leading] == 0) continue;

                    //cout<<len<<", "<<mod<<", "<<limit<<", "<<leading<<" -> "<<dp[len][mod][limit][leading]<<"\n";

                    if(leading) {
                        dp[len+1][mod][0][1] += dp[len][mod][limit][1];
                        if(limit) {
                            for(int ndigit=1;ndigit<(x[len]-'0');ndigit++) {
                                dp[len+1][(mod+ndigit)%d][0][0] += dp[len][mod][limit][leading];
                                dp[len+1][(mod+ndigit)%d][0][0] %= modd;
                            }
                            dp[len+1][(mod+(x[len]-'0'))%d][1][0] += dp[len][mod][limit][leading];
                            dp[len+1][(mod+(x[len]-'0'))%d][1][0] %= modd;
                        }
                        else {
                            for(int ndigit=1;ndigit<=9;ndigit++) {
                                dp[len+1][(mod+ndigit)%d][0][0] += dp[len][mod][limit][leading];
                                dp[len+1][(mod+ndigit)%d][0][0] %= modd;
                            }
                        }
                    }
                    else {
                        if(limit) {
                            for(int ndigit=0;ndigit<(x[len]-'0');ndigit++) {
                                dp[len+1][(mod+ndigit)%d][0][0] += dp[len][mod][limit][leading];
                                dp[len+1][(mod+ndigit)%d][0][0] %= modd;
                            }
                            dp[len+1][(mod+(x[len]-'0'))%d][1][0] += dp[len][mod][limit][leading];
                            dp[len+1][(mod+(x[len]-'0'))%d][1][0] %= modd;
                        }
                        else {
                            for(int ndigit=0;ndigit<=9;ndigit++) {
                                dp[len+1][(mod+ndigit)%d][0][0] += dp[len][mod][limit][leading];
                                dp[len+1][(mod+ndigit)%d][0][0] %= modd;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<dp[x.length()][0][0][0] + dp[x.length()][0][1][0]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>x>>d;
    solve();
    return 0;
}
