#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#define INF 10000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;
using namespace std;
queue<int> vertex;
int n;
int ans = 0;
int graph[10][10] = { };
void dfs(int p, int check[]){
	int t = 1;
	REP(i, n){
		if(check[i] == 0) t = 0;
	}
	if(t == 1) ans++;
	REP(i, n){
		if(graph[p][i] == 1 && check[i] == 0){
			check[i] = 1;
			dfs(i, check);
			check[i] = 0;
		}
	}
	return;
}
int main(){
	int m;
	cin >> n >> m;
	int check[n] = { };
	REP(i, m){
		int a, b;
		cin >> a >> b;
		graph[a-1][b-1] = 1;
		graph[b-1][a-1] = 1;
	}
	check[0] = 1;
	dfs(0, check);
	cout << ans << endl;
	return 0;
}
