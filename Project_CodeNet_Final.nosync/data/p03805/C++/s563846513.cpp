#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;
vector<int> v[10];
bool used[10];
int n,m,ans;
void dfs(int x,int cnt){
	if(cnt==n)ans++;
	for(auto to:v[x]){
		if(!used[to]){
			used[to]=true;
			dfs(to,cnt+1);
			used[to]=false;
		}
	}
}
int main(){
   cin>>n>>m;
   rep(i,m){
	   int x,y;
	   cin>>x>>y;
	   x--;y--;
	   v[x].push_back(y);
	   v[y].push_back(x);
   }
   used[0]=true;
   dfs(0,1);
   cout<<ans<<endl;
   return 0;
}