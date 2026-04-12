#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string t;int num;cin >> t >> num;
    int n = t.size();
    vector<vector<vl>> dp(n+10, vector<vl>(2,vl(num,0)));
    dp[0][0][0] = 1;
    for(int i=0;i<n;++i){
        int D = t[i] - '0';
        for(int k=0;k<num;++k){
            for(int j=0;j<2;++j){
                for(int d=0;d<=(j?9:D);++d){
                    dp[i+1][j || (d<D)][(k+d)%num] += dp[i][j][k];
                    dp[i+1][j || (d<D)][(k+d)%num] %= MOD;
                }
            }
        }
    }
    cout << (dp[n][0][0] + dp[n][1][0] - 1 + MOD) % MOD << endl;
}