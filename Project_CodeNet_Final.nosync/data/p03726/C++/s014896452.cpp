#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define int long long
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
template<class T>inline void chmin(T &a,T b){a=min(a,b);}
template<class T>inline void chmax(T &a,T b){a=max(a,b);}

int N;
vector<int>G[100005];
bool used[100005];
int dis[100005],par[100005];
bool match[100005];
int ans;
void dfs(int x){
	used[x]=true;
	for(int i:G[x]){
		if(!used[i]){
			dis[i]=dis[x]+1;
			par[i]=x;
			dfs(i);
		}
	}
}
signed main(){
	cin>>N;
	rep(i,N-1){
		int a,b;cin>>a>>b;a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0);
	vector<P>v;
	rep(i,N)v.push_back({dis[i],i});
	sort(all(v),greater<>());
	rep(i,N-1){
		if(!match[v[i].second]&&!match[par[v[i].second]]){
			match[par[v[i].second]]=true;
			ans++;
		}
	}
	if(ans*2==N)cout<<"Second"<<endl;
	else cout<<"First"<<endl;
}
