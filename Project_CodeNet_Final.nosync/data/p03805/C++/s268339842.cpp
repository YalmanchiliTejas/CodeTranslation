#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i = a; i <= n; i++)

#define ff              first
#define ss              second
#define ll              long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1

//const int mod=1000000007;
/*int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
*/

/*int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}
*/

bool graph[8][8];

int dfs(int v, int n , bool visited[8] )
{


	bool all_visited = true;

	for (int i = 0; i < n; ++i) {
		if (visited[i] == false)
			all_visited = false;
	}

	if (all_visited) {
		return 1;
	}

	int ret = 0;

	for (int i = 0; i < n; ++i) {
		if (graph[v][i] == false) continue;
		if (visited[i]) continue;

		visited[i] = true;
		ret += dfs(i, n, visited);
		visited[i] = false;
	}

	return ret;


}



int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt", "w" , stdout);
#endif

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{

		int x, y;
		cin >> x >> y;

		graph[x - 1][y - 1] = graph[y - 1][x - 1] = true;

	}

	bool visited[8];

	for (int i = 0; i < n; i++)
		visited[i] = false;


	visited[0] = true;

	cout << dfs(0, n, visited) << endl;


}