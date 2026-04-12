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
#define BE begin()
#define EN end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
int N;
int A[100010];
int dp[100010];
bool C(int x,int q){
  return dp[x]<q;
}
int upper(int l,int r,int q){//条件を満たす中で最小のものを返す
  int lb=l-1,ub=r+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(C(mid,q)) ub=mid;
    else lb=mid;
  }
  return ub;
}
void solve(){
  fill(dp,-1);
  rep1(i,N){
    int index=upper(1,N,A[i-1]);
    dp[index]=A[i-1];
  }
  rep1(i,N+1){
    if(dp[i]==-1){
      prin(i-1);
      break;
    }
  }
}
int main(){
  cin>>N;
  rep(i,N) cin>>A[i];
  solve();
  return 0;
}
