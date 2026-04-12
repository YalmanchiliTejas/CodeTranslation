#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<deque>
#include<cstdio>
#include<cstdio>
#include<time.h>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define pd(a,n) for(int i=0;i<n;i++)cout<<a[i]<<((i==n-1)?"\n":" ")
#define pdd(a,n,m)for(int i=0;i<m;i++)pd(a,m)
#define mp make_pair
#define pb push_back
#define ll __int64
#define __int64 long long
#define P pair<int,int>
#define PP pair<P,int>

string s;
ll k;
ll dp[1111][2][5];
ll N[1111];

int main(){
  cin>>s>>k;
  int n=s.size();
  rep(i,n)N[i]=s[i]-'0';
  dp[0][0][0]=1;
  rep(i,n){
    rep(f,2){
      rep(j,4){
        for(int x=0;x<=(f?9:N[i]);x++){
          if(x!=0)dp[i+1][f||x<N[i]][j+1]+=dp[i][f][j];
          else dp[i+1][f||x<N[i]][j]+=dp[i][f][j];
        }
      }
    }
  }
  cout<<dp[n][0][k]+dp[n][1][k]<<endl;

  return 0;
}
