#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
string s;
int K;
ll dp[110][2][5];//dp[i][j][k] 上i桁　flag k:0でない数字の数


int main(){cout<<fixed<<setprecision(20);
           //桁dp
           cin>>s>>K;
           int n=s.size();
           dp[0][0][0]=1;
           rep(i,1,n+1){
             rep(k,0,4){
               int h=s[i-1]-'0';
                rep(l,0,10){
                  //0>0
                  if(l==h&&h==0)dp[i][0][k]+=dp[i-1][0][k];
                  else if(l==h&&h!=0&&k-1>=0)dp[i][0][k]+=dp[i-1][0][k-1];
                  //0>1
                  if(l<h){
                    if(l==0)dp[i][1][k]+=dp[i-1][0][k];
                    else{
                     if(k-1>=0)dp[i][1][k]+=dp[i-1][0][k-1]; 
                    }
                  }
                  //1>1
                  if(l==0){
                    dp[i][1][k]+=dp[i-1][1][k];
                  }
                  else{
                   if(k-1>=0) dp[i][1][k]+=dp[i-1][1][k-1];
                  }
                }
             }
           }
           cout<<dp[n][0][K]+dp[n][1][K]<<endl;
}