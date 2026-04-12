#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 1000000007
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
//typedef long long int ll;
typedef pair<int,int> P;
struct edge{int to,cost;};

int ans;
int n,m;
vector<int> v[1111];
void dfs(int i,map<int,int> flag,int cnt){
	flag[i]=1;
	for(auto x:v[i]){
		if(!flag[x])dfs(x,flag,cnt+1);
	}
	if(cnt==n)ans++;
}

signed main(){
	
	cin>>n>>m;
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	map<int,int> hoge;
	dfs(0,hoge,1);
	cout<<ans<<endl;
	

	
}