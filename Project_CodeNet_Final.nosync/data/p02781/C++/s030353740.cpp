#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
const double PI=3.141592653589;
const int INF=1000000007;
const ll LMAX=1000000000000001;
const ll mod=1000000007;
ll gcd(ll a,ll b){if(a<b)swap(a,b);while((a%b)!=0){a=b;b=a%b;}return b;}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

ll dp[105][4][2];

int main(){
  string s; cin>>s;
  int k,n; cin>>k;
  n=s.size();
  // rep(i,3){
  //   rep(j,2) dp[0][i][j]=0;
  // }
  dp[0][0][0]=1;
  // dp[0][0][1]=1;

  rep(i,n){
    rep(j,k+1){
      rep(l,2){
        int c=s[i]-'0';
        if(l==0){
          if(j-1>=0&&c>0) dp[i+1][j][0]=dp[i][j-1][0];
          else if(c==0) dp[i+1][j][0]=dp[i][j][0];
          else dp[i+1][j][0]=0;
        }else{
          if(j==0){
            dp[i+1][j][1]=1;
          }else{
            if(c>0) dp[i+1][j][1]+=dp[i][j][0];
            if(c-1>0) dp[i+1][j][1]+=dp[i][j-1][0]*(c-1);
            dp[i+1][j][1]+=dp[i][j-1][1]*9+dp[i][j][1];
          }
        }
      }
    }
  }
  /*cout<<"0dayo"<<endl;
  rep(i,n+1){
    rep(j,k+1)
    cout<<dp[i][j][0]<<" ";
    cout<<endl;
  }
  cout<<"1dayo"<<endl;
  rep(i,n+1){
    rep(j,k+1)
    cout<<dp[i][j][1]<<" ";
    cout<<endl;
  }*/

  cout<<dp[n][k][0]+dp[n][k][1]<<endl;
  return 0;
}
