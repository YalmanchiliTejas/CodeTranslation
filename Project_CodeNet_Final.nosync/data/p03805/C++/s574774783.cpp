#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <cstring>
#include <cmath>

#define v_exists(elem, v) find(v.begin(),v.end(),elem)!=v.end()
#define s_exists(elem, s) s.find(elem)!=s.end()

using namespace std;
const int MOD = 1000000007;

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long lcm( long m, long n ){
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;

	return ((m / gcd(m, n)) * n);
}


long kake(long x, long y){
	return x * y % MOD;
}

long fact_mod(long x){
	long ans = x;
	x-=1;
	while(x>1){
		ans = ans * x % MOD;
		x-=1;
	}
	return ans;
}

int N,M,cnt;
int adj[8][8];
bool visited[8];


void dfs(int node){
	visited[node] = true;

	int passed = 0;
	for(int i=0; i<N; i++){
		passed += visited[i];
	}

	if(passed == N){
		cnt+=1;
	}

	for(int i=0; i<N; i++){

		if(adj[node][i]==1 && visited[i]==false){
			dfs(i);
			visited[i] = false;
		}
	}
}

int main(){

	memset(adj, 0, sizeof(adj));
	memset(visited, 0, sizeof(visited));
	cnt = 0;

	cin >> N >> M;

	for(int i=0; i<M; i++){
		int a,b;
		cin >> a >> b;
		adj[a-1][b-1] = 1;
		adj[b-1][a-1] = 1;
	}

	dfs(0);
	cout << cnt << endl;

}