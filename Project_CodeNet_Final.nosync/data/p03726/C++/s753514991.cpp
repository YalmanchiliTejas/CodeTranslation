#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int N = 100000 + 100;
const int MOD = 1000000007;
const int oo = 1e9;

int n , a , b;
vector<int> g[N];

int solve(int u , int p){
	int total = 0;
	for (int i = 0; i < g[u].size(); ++i){
		int v = g[u][i];
		if(v==p)continue;
		total += solve(v,u);
	}
	if(total>1){
		puts("First");
		exit(0);
	}
	return !total;
}
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n-1; ++i){
		scanf("%d%d",&a,&b);
		g[a].pb(b);
		g[b].pb(a);
	}
	if(solve(1,-1)){
		puts("First");
	}else{
		puts("Second");
	}
	return 0;
}