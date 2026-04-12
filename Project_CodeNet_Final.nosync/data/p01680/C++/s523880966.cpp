#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

int N, M;

int parent[100005];
void init()
{
	for(int i = 1; i <= N; i++){
		parent[i] = i;
	}
}

int root(int i)
{
	if(parent[i] == i) return i;
	return parent[i] = root(parent[i]);
}

bool same(int i, int j)
{
	return root(i) == root(j);
}

void unite(int i, int j)
{
	int root_i = root(i), root_j = root(j);
	if(root_i == root_j) return;
	parent[root_i] = root_j;
}

llint pow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2) return ((a % mod) * (pow(a, n-1) % mod)) % mod;
	llint t = pow(a, n/2);
	return ( (t%mod) * (t%mod) ) % mod;
}

int main(void)
{
	while(1){
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		
		init();
		
		int a, b;
		for(int i = 0; i < M; i++){
			cin >> a >> b;
			unite(a, b);
		}
		
		llint X = 0;
		for(int i = 1; i <= N; i++) if(parent[i] == i) X++;
		
		llint ans = pow(2, X);
		if(M) ans++;
		cout << ans % mod << endl;
	}
	
	return 0;
}