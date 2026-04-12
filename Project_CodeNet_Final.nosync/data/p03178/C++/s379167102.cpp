#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef set<int> si;
typedef string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
str K;
int D;
ll dp[100010][110][2];
int main(){
  cin>>K>>D;
  int s=K.size();
  vi n;
  rep(i,s){
    n.pb(K[i]-'0');
  }
  fill(dp,0);
  dp[0][0][0]=1;
  rep(i,s){
    rep(j,D){
      rep(k,2){
	rep(l,(k?10:n[i]+1)){
	  dp[i+1][(j+l)%D][k||l<n[i]]=(dp[i+1][(j+l)%D][k||l<n[i]]+dp[i][j][k])%MOD;
	}
      }
    }
  }
  prin((dp[s][0][0]+dp[s][0][1]-1+MOD)%MOD);
  return 0;
}
