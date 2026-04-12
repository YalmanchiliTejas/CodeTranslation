#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <ctime>
#include <list>
#include <numeric>
#include <utility>
#include <ctime>
#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007
 
#define rep(i,n) for(int i=0;i<int(n);i++)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair
#define MOD(x) (x%(mod))
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
 
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
bool debug=false;
 
/*---------------------------------------------------*/
/*
int h,w;
char maze[10][10];
int dx[2]={1,0};
int dy[2]={0,1};

bool dfs(int x,int y){
  cout<<x<<" "<<y<<endl;
  bool ok=false;
  if(x==w-1&&y==h-1){
    return true;
  }else{
    rep(i,2){
      if(maze[y+dy[i]][x+dx[i]]=='#'){
	ok=dfs(x+dx[i],y+dy[i]);
      }
      if(ok)return ok;
    }
  }
  return ok;
}

int main(){
  cin>>h>>w;
  rep(i,h)rep(j,w)cin>>maze[i][j];
  if(dfs(0,0))cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  return 0;
}
*/

int main(){
  int h,w,cnt=0;
  cin>>h>>w;
  rep(i,h)rep(j,w){
    char c;
    cin>>c;
    if(c=='#')cnt++;
  }
  if(cnt==w+h-1)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}
