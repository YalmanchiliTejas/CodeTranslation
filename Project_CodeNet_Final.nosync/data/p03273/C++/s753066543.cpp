#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <tuple>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>

#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long>vll;
typedef pair<int,int> pi;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

int main(){
  int h,w;
  char m[105][105];
  cin>>h>>w;
  rep(i,h)rep(j,w)cin>>m[i][j];
  rep(i,h){
    bool ok=true;
    rep(j,w){
      if(m[i][j]=='#')ok=false;
    }
    if(ok)rep(j,w)m[i][j]='-';
  }

  rep(i,w){
    bool ok=true;
    rep(j,h){
      if(m[j][i]=='#')ok=false;
    }
    if(ok)rep(j,h)m[j][i]='-';
  }

  
  rep(i,h){
    bool is_output=false;
    rep(j,w){
      if(m[i][j]!='-'){
	cout<<m[i][j];
	is_output=true;
      }
    }
    if(is_output)cout<<endl;
  }
  return 0;
}
