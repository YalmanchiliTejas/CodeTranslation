#define _USE_MATH_DEFINES
#include<math.h>

//#include<cmath>

#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>



//#include "Ants.h"
using namespace std;
typedef long long ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define loop(n) for(int i=0;i<n;i++)
#define show(s) cout<<s<<endl;
typedef pair < int, int> P;
/****Union-Ford-Tree***/
int par[int(0x7ffffff)];//Parent
int Rank[int(0x7ffffff)];//Deep_of_the_Tree

//int a[100] = { 4,2,3,1,5 }, m[100] ={3,2,2};
//int n = 0;
//const ll mod = 1000000007;


//n要素で初期化
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		Rank[i] = 0;
	}
}
//木の根探し
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
//xとyの属する集合を併合
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;

	if (Rank[x] < Rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (Rank[x] == Rank[y])Rank[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

/************************************************************************************
//*無向グラフのBELL_MAN_FORD;*//*
struct edge { int from, to, cost; };
edge es[10000];
int d[10000];
void shortest_path(int s) {
	for (int i = 0; i < V; i++)d[i] = INF;
	d[s] = 0;
	while (true) {
		bool update = false;
		for (int i = 0; i < E*2; i++) {
			edge e = es[i];
			if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if (!update)break;
	}

}
int main() {
	cin >> V >> E;
	for (int i = 0; i < E*2; i = i+2) {
		edge e;
		cin >> e.from >> e.to >> e.cost;
		es[i] = e;
		swap(e.to, e.from);
		es[i + 1] = e;

	}
	shortest_path(0);
	cout << d[6] << endl;
}
*////////////////////////////////////////*
int gcd(int a, int b) {//最大公約数を求める
	if (b == 0) return a;
	return gcd(b, a % b);
}
/*****************************************************************************/
//int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1};
//vector<int> G[10000];


//struct edge { int to, cost; };
//vector<edge>G[100000];


/**************/


/****
//priority_queue<int> //大きいものから順番に出てくる
//priority_queue<int,vector<int>,greater<int>>//小さいものから出てくる（順位キュー）
.top();
.pop();
.empty();
**/
//void solve();
//int V, E;
//void shortest_path(int);

typedef long double ld;
typedef unsigned long long ull;
const int MX = 3007;

const int  MAX_N = 1 << 17;

//セグメント木
int Q, dat[2 * MAX_N - 1];
//要素数で初期化
void rmq_init(int n_) {
	Q = 1;
	while (Q < n_)Q *= 2;
	for (int i = 0; i < 2 * Q - 1; i++)dat[i] = INF;

}
//k番目をaに変更
void update(int k, int a) {
	k += Q - 1;
	dat[k] = a;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
}
//最小値探し(a,b,0,0,n)
int query(int a, int b, int k = 0, int l = 0, int r = Q) {

	if (r <= a || b <= l)return INF;

	if (a <= l && r <= b)return dat[k];
	else {

		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
}




//vector<P> que;


typedef vector<ll> vec;
typedef vector<vec> mat;
const int M = 4;

//A*B　Matrix
mat mul(mat& A, mat& B) {
	mat C(A.size(), vec(B[0].size()));
	for (int i = 0; i < A.size(); i++)for (int k = 0; k < B.size(); k++)
		for (int j = 0; j < B[0].size(); j++)
			C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;

	return C;
}

//A^n　行列専用
mat pow(mat A, ll n) {
	mat B(A.size(), vec(A.size()));
	for (int i = 0; i < A.size(); i++)B[i][i] = 1;
	while (n > 0) {
		if (n & 1)B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}
int N, A[100005],B[100005],num;
int main()
{
	cin >> N;
	loop(N) {
		cin >> A[i];
	}
	num++;
	B[0] = A[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		//cout << B[num - 1] << endl;
		if (A[i] >= B[num - 1]) {
			
			B[num++] = A[i];
			//sort(B, B + num);
			continue;
		}
		int p = upper_bound(B, B + num, A[i])-A;
		A[p] = A[i];
	}
	cout << num << endl;
		
}
