#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000000000000007;
const int MOD=1000000007;
int n;
int a[4000]={};
int memo[4000][4000][2];
//0->太郎くん, 1->次郎くん
int rec(int l,int r,int t){
    if(t==0){
        if(memo[l][r][0]!=inf){
            return memo[l][r][0];
        }
        else{
            memo[l][r][0]=max(rec(l+1,r,1)+a[l],rec(l,r-1,1)+a[r]);
            return memo[l][r][0];
        }
    }
    else{
        if(memo[l][r][1]!=inf){
            return memo[l][r][1];
        }
        else{
            memo[l][r][1]=min(rec(l+1,r,0)-a[l],rec(l,r-1,0)-a[r]);
            return memo[l][r][1];
        }
    }
    return 0;
}
signed main(){
  cin>>n;
  rep(i,n)cin>>a[i];
  rep(i,n+5){
      rep(j,n+5){
          memo[i][j][0]=inf;
          memo[i][j][1]=inf;
      }
  }
  rep(i,n+5){
      memo[i][i][0]=a[i];
      memo[i][i][1]=-a[i];
  }
  cout<<rec(0,n-1,0)<<endl;
  /*
  rep(i,n){
      rep(j,n){
          cout<<memo[i][j][0]<<" ";
      }
      cout<<endl;
  }*/
  return 0;
}