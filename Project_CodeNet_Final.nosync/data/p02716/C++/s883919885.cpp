#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
using P=pair<long long,long long>;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll dp1[200200][2];
ll dp2[200200][2][2];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  ll n;
  cin >> n;
  vector<ll>a(n);
  rep(i,n) cin >> a[i];
  rep(i,n){
    dp1[i][0]=dp1[i][1]=-INF;
    dp2[i][0][0]=dp2[i][1][0]=dp2[i][0][1]=dp2[i][1][1]=-INF;
  }
  ll m=n/2;
  if(n%2==0){
    dp1[1][0]=a[0];
    dp1[1][1]=a[1];
    for(int i=1;i<m;i++){
      rep(j,2){
        if(j==0)dp1[i+1][0]=max(dp1[i+1][0],dp1[i][0]+a[2*i]);
        dp1[i+1][1]=max(dp1[i+1][1],dp1[i][j]+a[2*i+1]);
      }
    }
    cout << max(dp1[m][0],dp1[m][1]) << endl;
  }
  
  else{
    dp1[1][0]=a[0];
    dp1[1][1]=a[1];
    for(int i=1;i<m;i++){
      rep(j,2){
        if(j==0)dp1[i+1][0]=max(dp1[i+1][0],dp1[i][0]+a[2*i]);
        dp1[i+1][1]=max(dp1[i+1][1],dp1[i][j]+a[2*i+1]);
      }
    }
    dp2[1][0][0]=a[0]+a[n-1];
    dp2[1][1][0]=a[1]+a[n-1];
    dp2[1][0][1]=a[n-1];
    for(int i=1;i<n/2;i++){
      rep(j,2){
        rep(k,2){
          if(k==0){
            dp2[i+1][0][1]=max(dp2[i+1][0][1],dp2[i][j][k]);
          }
          if(j==0){
            dp2[i+1][0][k]=max(dp2[i+1][0][k],dp2[i][0][k]+a[2*i]);
          }
          if(i!=m-1){
            dp2[i+1][1][k]=max(dp2[i+1][1][k],dp2[i][j][k]+a[2*i+1]);
          }
        }
      }
    }
    cout << max({dp1[m][0],dp1[m][1],dp2[m][0][1],dp2[m][1][1]});
  }
}
