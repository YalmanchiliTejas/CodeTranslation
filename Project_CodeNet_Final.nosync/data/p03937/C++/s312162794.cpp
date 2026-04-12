#include<bits/stdc++.h>
#define inf 1<<29
#define linf 1e16
#define eps (1e-8)
#define mod 1000000007
#define pi acos(-1)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10f\n",(double)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a)-1;(b)<=i;i--)
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef vector<int> vi;
typedef vector<pii> vpi;
const int dx[8]={1,0,-1,0,1,1,-1,-1};
const int dy[8]={0,1,0,-1,1,-1,1,-1};

int main()
{
  int h,w;
  string grid[10];
  bool flag=true;

  cin>>h>>w;
  FOR(i,0,h)cin>>grid[i];
  FOR(i,0,h-1){
    FOR(j,0,w-1){
      if(grid[i][j]=='#'){
        if(grid[i][j+1]=='#' && grid[i+1][j]=='#')flag=false;
        if(grid[i][j+1]=='.' && grid[i+1][j]=='.')flag=false;
      }
    }
  }
  FOR(i,1,h){
    FOR(j,1,w){
      if(grid[i][j]=='#'){
        if(grid[i][j-1]=='#' && grid[i-1][j]=='#')flag=false;
        if(grid[i][j-1]=='.' && grid[i-1][j]=='.')flag=false;
      }
    }
  }
  if(flag)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;

  return 0;
}

