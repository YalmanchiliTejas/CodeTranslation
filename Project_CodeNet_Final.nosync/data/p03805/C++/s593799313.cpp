#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <time.h>

using namespace std;
typedef long long ll;
#define pl pair<ll,ll>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define dbg(x) cout << #x"="<< (x) << endl
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a) 
#define in(x) cin >> x;
#define all(x) (x).begin(), (x).end()
#define INF 2147483600
#define fi first
#define se second
ll n,m,x,y,cnt=0;
vector<ll> flag(9);
vector<vector<ll>> a(9),b(9);

bool judge(vector<ll> flag){
	ll ans=1;
	FOR(i,1,n+1)ans *=flag[i];		
	return ans?true:false;
}

void dfs(int i){
	flag[i]=1;
	if(judge(flag)){
		cnt++;
		flag[i]=0;
		return;
	}
	rep(j,a[i].size())
	if(flag[a[i][j]]==0)dfs(a[i][j]);
	rep(j,b[i].size())
	if(flag[b[i][j]]==0)dfs(b[i][j]);
	flag[i]=0;
	return;
}

int main(){
	cin>>n>>m;
	rep(i,m){
		cin>>x>>y;
		a[x].pb(y);b[y].pb(x);
	}
	dfs(1);
	cout<<cnt<<endl;
    return 0;
}