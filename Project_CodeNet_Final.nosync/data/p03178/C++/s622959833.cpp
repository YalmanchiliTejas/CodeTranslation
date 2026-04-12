#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;

ll dp[10101][101][2]={};//左からの桁数、modD,数値未満かどうか

int main(){
  string k;
  int D,n;
  cin >>k;
  cin >>D;
  n=k.size();
  dp[0][0][0]=1;

  rep(dgt,n){
    rep(d,D){
      rep(less,2){
        int c=k[dgt]-'0';
        for(int nxt=0;nxt<=(less?9:c);nxt++){//(lessが1なら9,0ならcを返す)
          dp[dgt+1][(d+nxt)%D][nxt<c || less]+=dp[dgt][d][less]%mod;
        }
      }
    }
  }
  cout << (dp[n][0][0]+dp[n][0][1]-1)%mod << endl;
}