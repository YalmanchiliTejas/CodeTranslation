#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define sz size
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORN(i,a,b) for(int i=a;i<=b;i++)
#define FORRN(i,a,b) for (int i = (a); i >= (b); i--)
#define FORR(i,a,b) for (int i = (a); i > (b); i--)
typedef unsigned long long ull;
typedef long long ll;

int n,m;
vector<int> G[105];
bool vis[105];

int dfs(int v){
	bool allVisited=true;

	FOR(i,0,n){
		if(!vis[i])
			allVisited=false;
	}
	if(allVisited)
		return 1;
	int res=0;

	for(auto i: G[v]){
		if(vis[i])
			continue;
		if(!vis[i]){
			vis[i]=true;
			res+=dfs(i);
			vis[i]=false;
		}
	}
	return res;
}

int main(){
    ios_base::sync_with_stdio(false); //Fast I/O
    cin.tie(0);
    cout.tie(0);
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);

    cin >> n >> m;
    FOR(i,0,m){
    	int a,b;
    	cin >> a >> b;
    	a--;b--;
    	G[a].pb(b);
    	G[b].pb(a);
    }

    memset(vis,false,sizeof(vis));
    vis[0]=true;

    cout << dfs(0) << endl;

    return 0;
}
