#include<bits/stdc++.h>
#define MAX 51
#define inf 1<<29
#define linf (1e16)
#define eps (1e-8)
#define Eps (1e-12)
#define mod 1000000007
#define pi acos(-1.0)
#define phi (1.0+sqrt(5.0))/2.0
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10f\n",(double)(a))
#define pld(a) printf("%.10Lf\n",(ld)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a)-1;(b)<=i;i--)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

int h,w;
string grid[MAX];
int memo[MAX][MAX][4];

bool in(int y,int x){
  if(x<0 || y<0 || w<=x || h<=y)return false;
  return true;
}

bool cal(int sy,int sx,int gy,int gx,int sd){
  int cx=sx,cy=sy,cd=sd;
  memo[cy][cx][sd]=1;
  while(1){
    FOR(i,0,4){
      int nd = (cd+3+i)%4;
      int nx = cx+dx[nd],ny = cy+dy[nd];
      if(in(ny,nx) && grid[ny][nx]=='.'){
        cx = nx;
        cy = ny;
        cd = nd;
        break;
      }
      if(i==3)return false;
    }
    memo[cy][cx][sd]=1;
    if(cy==gy && cx==gx)break;
    if(cy==sy && cx==sx)return false;
  }
  return true;
}

bool chip(int y,int x){
  if(y==0 && x==0)return true;
  if(y==h-1 && x==0)return true;
  if(y==0 && x==w-1)return true;
  if(y==h-1 && x==w-1)return true;
  return false;
}

string solve(){
  FOR(i,0,h)
    FOR(j,0,w)
      FOR(k,0,4)memo[i][j][k] = 0;
  if(!cal(0,0,h-1,0,0))return "NO";
  if(!cal(h-1,0,h-1,w-1,1))return "NO";
  if(!cal(h-1,w-1,0,w-1,2))return "NO";
  if(!cal(0,w-1,0,0,3))return "NO";
  FOR(i,0,h){
    FOR(j,0,w){
      int sum = memo[i][j][0]+memo[i][j][1]+memo[i][j][2]+memo[i][j][3];
      if(chip(i,j) && sum!=2)return "NO";
      if(!chip(i,j) && 1<sum)return "NO";
    }
  }
  return "YES";
}

int main()
{
  while(cin>>h>>w && h){
    FOR(i,0,h)cin>>grid[i];
    cout<<solve()<<endl;
  }
  return 0;
}

