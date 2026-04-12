#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end());
#define fill(a,x) memset(a,x,sizeof(a))
#define zero(a) fill(a,0)
#define minus(a) fill(a,-1)
#define dbg(x) cout << #x"=" << x << endl

const int INF=INT_MAX/3;
const int LIMIT=9;

int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};

int h,w;
string s[LIMIT];

bool dfs(int y,int x){
  if(s[y][x]=='.')return false;
  if(y==h-1&&x==w-1)return true;
  if(y>=h)return false;
  if(x>=w)return false;
  if(dfs(y+1,x))return true;
  if(dfs(y,x+1))return true;
}

bool check(){
  rep(i,h){
    rep(j,w){
      if(i+1<h&&j+1<w&&s[i+1][j]=='#'&&s[i][j+1]=='#') return false;
    }
  }
  return true;
}

int main(){
  cin>>h>>w;
  rep(i,h)cin>>s[i];
  if(dfs(0,0)&&check())cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  return 0;
}