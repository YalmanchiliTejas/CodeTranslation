#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vector<ll> > vvl;
typedef vector<vector<P> > vvp;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


// dp[keta][just or smaller][cnt] dp[n.size()][0][k],dp[n.size()][1][k]
ll dp[110][4][2]={};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  string s;
  int K;
  cin >> s >> K;
  
  int n=s.size();
  
  dp[0][0][0]=1;
  rep(i,n){
    rep(j,4){
      rep(k,2){
        int c=s[i]-'0';
        
        rep(d,10){
          int ni=i+1,nj=j,nk=k;
          if(d!=0)nj++;
          if(nj>K)continue;
          if(k==0){
            if(d>c)continue;
            else if(d<c)nk=1;
          } 
          dp[ni][nj][nk]+=dp[i][j][k];
        }
      }
    }
  }
  cout << dp[n][K][1]+dp[n][K][0] << endl;
  return 0;     
}
