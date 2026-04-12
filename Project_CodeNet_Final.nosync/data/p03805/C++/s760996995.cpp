
// Problem : C - One-stroke Path
// Contest : AtCoder - AtCoder Beginner Contest 054
// URL : https://atcoder.jp/contests/abc054/tasks/abc054_c
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define all(a) a.begin(),a.end()
#define x first
#define y second
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
int tot;
int n,m;
void dfs(int i,vi *adj,vi &visited,int inStack){
	visited[i] = 1;
	for(auto j:adj[i]){
		if(!visited[j])dfs(j,adj,visited,inStack+1);
	}
	if(inStack == n)tot++;
	visited[i] = 0;
}
int main() {
    // your code goes here
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vi adj[n+1];
    for(int i = 0;i<m;i++){
    	int u,v;
    	cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    vi visited(n+1,0);
    tot=0;
    dfs(1,adj,visited,1);
    cout << tot << "\n";
    return 0;
}
