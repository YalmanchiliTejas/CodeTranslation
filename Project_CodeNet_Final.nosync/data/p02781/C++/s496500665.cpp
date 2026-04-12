#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
int dp[105][4][2];
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int l = s.size();
    dp[0][0][0]=1;
    rep(i,l){
        rep(j,4){
            rep(x,2){
                int ny = s[i] - '0';
                rep(y,10){
                    int ni = i + 1, nj = j, nx = x;
                    if(y!=0)
                        nj++;
                    if(nj>k)
                        continue;
                    if(x==0){
                        if(y>ny)
                            continue;
                        if(y<ny)
                            nx = 1;
                    }
                    dp[ni][nj][nx] += dp[i][j][x];
                }

            }
        }
    }
    int ans = dp[l][k][0] + dp[l][k][1];
    cout <<  ans << endl;
}