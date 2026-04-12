#include <bits/stdc++.h>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define rep(i,a,b) for(int (i)=int(a);(i)<int(b);(i)++)
#define rrep(i,a,b) for(int (i)=int(a);(i)>=int(b);(i)--)

#define put(a) cout << (a) << endl
#define puts(a) cout << (a) << " "

#define llint long long int

#define INF (long long)(1e9+1)
#define MOD (long long)(1e9+7)
#define INF64 (long long)(1e18+1)

#define F first
#define S second

#define Pii  pair<int,int>
#define Pll  pair<long long,long long>
#define Piii pair<int,pair<int,int>>
#define Plll pair<long long,pair<long long,long long>>

#define Vll(a,b,c)    vector<vector<long long>> (a)((b),vector<long long>((c))
#define Vlll(a,b,c,d) vector<vector<vector<long long>>> (a)((b),vector<vector<long long>>((c),vector<long long>((d)))

#define MAX_N 1000000

llint my_binary_search(llint ary[], llint key, llint left, llint right) {
	llint middle;
	if (right < left) {
		return -(INF64);
	} else {
		middle = left + (right - left) / 2;
		if (ary[middle] > key) {
			return my_binary_search(ary, key, left, middle - 1);
		} else if (ary[middle] < key) {
			return my_binary_search(ary, key, middle + 1, right);
		} else {
			return middle;
		}
	}
}

struct UnionFind {
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

	UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
		for(int i = 0; i < N; i++) par[i] = i;
	}

	int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) { // xとyの木を併合
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}

	bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};

int main (void)
{
	//INPUT
	llint N,M;
	cin >> N >> M;


	string ans;
	//SOLVE
	if (N==M) {
		ans = "Yes";
	} else {
		ans = "No";
	}

	//OUTPUT
	cout << ans << endl;

	return 0;
}
