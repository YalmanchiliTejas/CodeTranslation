#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

ll dp[110][5][2];

int main(){
  string s; cin >> s;
  int K; cin >> K;
  int n=s.size();
  dp[0][0][0]=1;
  rep(i,n)rep(j,4)rep(k,2){
    int nd=s[i]-'0';
    rep(d,10){
      int ni=i+1;
      int nj=j;
      int nk=k;
      if(k==0){
        if(d>nd) continue;
        if(d<nd) nk=1;
      }
      if(d!=0) nj++;
      dp[ni][nj][nk]+=dp[i][j][k];
    }
  }
  cout << dp[n][K][0]+dp[n][K][1] << endl;
}