#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>

#define INF 9999999999
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define MOD(x) (x%(mod))
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int>pi;

/*---------------------------------------------------*/

bool used[10];
int d[10][10];
int n,m;

int dfs(int now,int cnt){
  int sum=0;
  //cout<<"now"<<now<<" cnt"<<cnt<<endl;

  if(cnt==n)return 1;
  for(int i=1;i<=n;i++){
    if(d[now][i]&&!used[i]){
      used[i]=true;
      //cout<<"now"<<now<<" cnt"<<cnt<<endl;
      sum+=dfs(i,cnt+1);
      used[i]=false;
    }
  }
  return sum;
}

int main(){
  cin>>n>>m;
  int a,b;
  rep(i,m){
    cin>>a>>b;
    d[a][b]=1;
    d[b][a]=1;
  }
  used[1]=true;
  cout<<dfs(1,1)<<endl;
  return 0;
}
