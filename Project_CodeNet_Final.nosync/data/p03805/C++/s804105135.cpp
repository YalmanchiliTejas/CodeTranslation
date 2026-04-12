#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<30;
const ll  longinf = 1LL<<60;
const int mod=1000000007;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int n,m,a[8][8],visit[8],cnt;
void dfs(int x,int y){
  if(y==0)
    cnt++;
  else{
    rep(i,n){
      if(a[x][i]==1&&visit[i]==0){
        visit[i]=1;
        dfs(i,y-1);
        visit[i]=0;
        }
      }
    }
  }
int main(){
  cin>>n>>m;
  int l[m],r[m];
  rep(i,n)rep(j,n)a[i][j]=0;
  rep(i,m){
    cin>>l[i]>>r[i];
    a[l[i]-1][r[i]-1]=1;
    a[r[i]-1][l[i]-1]=1;
    }
  rep(i,n)visit[i]=0;
  visit[0]=1;
  cnt=0;
  dfs(0,n-1);
  cout<<cnt<<endl;
  return 0;
  }