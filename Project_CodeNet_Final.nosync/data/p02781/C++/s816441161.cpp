#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<ll,ll> P;
typedef pair<ll,ll> Pll;
//小数点以下　cout << fixed << setprecision(10) << num << endl;
//桁数はlog10(mid)でやれ　log(mid)/log(10)はWA
//long*long<0で判定するな
//開区間と閉区間
//アルファベットが何番目かは x=s[i]-'a'
//bfsはmain()内で　rep(i,h)rep(j,w)rep(i,4)でバグ
//切り上げ：(a+(b-1))/b
//32bit以上は 1ull<<j
// map 初期値0 for(auto itr=mp.begin();itr!=mp.end();++itr) itr->fi itr->se で全探索
// for(auto u:mp) u.fi u.se も可能
//n個のgcd,lcmは一つずつみて更新していく
//大きな数を扱うときは素因数分解した形で持っておく
// (l/a[i]) = l*powmod(a[i],MOD-2)%MOD;
//auto itr=lower_bound(ALL(a),key) a[itr-a.begin()]

int main(){
    string s; int k;
    cin >> s >> k;
    int n=s.size();
    int dp[n+1][k+1][2];
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    //dp[i][j][0]=nを下回ってない、iまで見て０でないものがj個
    rep(i,n){
        rep(j,k+1){
            int x=s[i]-'0';
            if(x==0){
                dp[i+1][j][0]+=dp[i][j][0];
            }else{
                if(j>0){
                    dp[i+1][j][0]+=dp[i][j-1][0];
                    dp[i+1][j][1]+=(x-1)*dp[i][j-1][0];
                }
                dp[i+1][j][1]+=dp[i][j][0];
            }
            dp[i+1][j][1]+=dp[i][j][1];
            if(j>0)dp[i+1][j][1]+=dp[i][j-1][1]*9;
        }
    }
    cout << dp[n][k][0]+dp[n][k][1] << endl;
}
