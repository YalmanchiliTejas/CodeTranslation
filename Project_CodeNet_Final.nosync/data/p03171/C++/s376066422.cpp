#include <bits/stdc++.h>
using namespace std;
// Macros for easier access
#define ll long long
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define test ll cases; cin>>cases; for(ll testCase = 1; testCase <= cases; testCase++)   //test cases
#define rep(i, begin, end, upd)  for(ll i = begin; ((begin < end && upd > 0 && i < end) || (begin > end && upd < 0 && i >= end)); i+=upd)
#define fill(name, val) memset(name, val, sizeof(name));
#define mop(a, op, b)    (a%mod op b%mod)%mod
#define error(x) fixed<<setprecision(x) //cout<<error(5)<<someDouble    -> example - 3.14159
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define get(a, n)    for(ll i = 0; i < n; i++)    cin>>a[i];
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(x) cerr << #x << " : " << (x) << endl
// Constants
#define MX 100001
#define mod 1000000007LL
#define inf 1000000000000000000LL
void init(){
	boost;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
/*  =======TL;DR=======
	Author : zenolus
	TreeNode (binary tree)[snippet key: tree]:
		TreeNode(v)   => create new node with val v
	Graph (Adjacency List representation)[snippet key: graph]:
		Graph(nodes, weighted = false, directed = false)  => create a graph with n nodes, specify if weighted
		addEdge(u, v, weight = 1)   => add an edge in graph, specify weight if necessary
		printEdges() => display the adjacency list
		dijkstra(src)    => single src all dest shortest distance. returns a map <node, dist> Ot(ElogV) Os(V)    use AUTO
		flowar()    => All pair shortest distance. returns 2D map <u, <v, d>>    Ot(V^3) Os(V^2)    use AUTO
		MST()    => Returns the edge list containing N - 1 edges forming the Kruskal's MST    Ot(ElogE) Os(V+E)    use AUTO
		toposort()    => returns dfs based topological sorted vector for DAGs        Ot(V+E) Os(V)    use AUTO
	SegTree (Segment Tree)[snippet key: segtree]:
		SegTree(arrayLength, array, queryBase)    => create the segment tree
		update(index, value)    => point update
		query(left, right)    => query segment operation on [l, r)
	Algorithms [snippet key: algo]:
		gcd(a, b)   => returns gcd of a and b
		power(x, n) => return x raised to power n in O(log n) time, if required, specify modulo
		fermatInv(x)  => returns modular multiplicative inverse of x with mod
		primeSieve(n = MX)   => returns a vector of all the primes till n
		factorize(n)    => returns a vector of factors of n
		modMult(a, b)    => returns (a*b)%mod
		idMatrix(matrix)    => returns an identity matrix of dimensions similar to passed matrix
		matrixMult(A, B)    => returns (A.B)%mod
		matrixExpo(A, n)    => returns A power n % mod
		nCr(n, r)  => returns nCr value % mod using Fermat's theorem. O(n + log p)
		nCrDP(n, r, p)    => returns nCr % p for small n, r, p    Ot(n*r), Os(n)
		smallnCr(n, r, p)    => returns nCr % p for small p using Lucas' theorem.    Ot(p^2 + log n base p), Os(p)
		linearRec(f, c, n)    => returns nth term of linear recurrence. F(n) = c1F(n-1) + c2F(n-2) + ... + ckF(n-k)
							Ex: linearRec({1, 2, 3}, {3, 4, 5}, 8)    => starting terms 1, 2, 3. c1 = 5, c2 = 5, c3 = 3. k = 3
*/
ll n;
ll a[3001];
ll dp[3001][3001][2];
ll solve(ll l, ll r, bool taro){
	if(l > r || l == n || r < 0)	return 0;
	ll* x = &dp[l][r][taro];
	if(*x != -1)	return *x;
	ll op1 = taro*a[l] - (!taro)*a[l] + solve(l+1, r, !taro);
	ll op2 = taro*a[r] - (!taro)*a[r] + solve(l, r-1, !taro);
	return *x = taro?max(op1, op2):min(op1, op2);
}
int main(){
	//init();
	cin>>n;	get(a, n);
	fill(dp, -1);
	cout<<solve(0, n-1, 1);
}