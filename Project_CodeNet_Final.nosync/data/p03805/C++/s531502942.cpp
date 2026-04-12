#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <stack>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <functional>

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
ll N,M;
int ans=0;
void solve();
vector<vector<int> > connect(10);
vector<int> flag(10);

void solve(int s){
	bool root=true;
	flag[s]=1;
	FOR(i,1,N+1){
		if(!flag[i]){
			root=false;
		}
	}
	if(root){
		ans++;
		flag[s]=0;
		return;
	}
	rep(i,connect[s].size()){
		if(flag[connect[s][i]]==0){
			solve(connect[s][i]);
		}	
	}
	flag[s]=0;
	return;
}

int main(){
	cin>>N>>M;
	int a,b;
	rep(i,M){
		cin>>a>>b;
		connect[a].pb(b);
		connect[b].pb(a);
	}

	solve(1);
	cout<<ans<<endl;

	return 0;
}












