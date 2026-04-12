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
#include<math.h>
//#include "Ants.h"
using namespace std;
typedef long long ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
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
/************************************************************************************/
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
/**************/

int main()
{
	int n;
	cin >> n;
	if (n == 7 || n == 5 || n == 3)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


}