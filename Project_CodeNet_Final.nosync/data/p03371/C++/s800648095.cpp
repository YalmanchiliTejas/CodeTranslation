#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
#include<unordered_map>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define sort(s) sort(s.begin(),s.end())
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind
#define rt (a); return (a); 
#define Pint pair<int,int>
#define Pll pair<ll,ll>
#define keta(a)  fixed << setprecision(a)
constexpr auto INF = 1000000000;
constexpr auto mod = 1000000007;
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0)return a;
	return gcd(b, a % b);
}
int n,q;
hei(ll) seg, lazy;

void aaa(int k) {
	if (lazy[k] == 0)return ;
	if (k < n - 1) {
		lazy[k * 2 + 1] += lazy[k];
		lazy[k * 2 + 2] += lazy[k];
	}
	seg[k] += lazy[k];
	lazy[k] = 0;
}

void update(int a, int b, ll x,int k,int l,int r) {
	aaa(k);
	if (a<=l && b>=r) {
		lazy[k] += x;
		aaa(k);
	}
	else if(a<r&&l<b){
		update(a, b, x, k * 2 + 1, l, (l + r) / 2);
		update(a, b, x, k * 2 + 2, (l + r) / 2, r);
		seg[k] = seg[k * 2 + 1]+seg[k * 2 + 2];
	}
}

ll query(int a,int b,int k,int l,int r){
	aaa(k);
	if (l >= b || r <= a)return 0;
	if (a <=l  && b >= r) {
		return seg[k];
	}
	ll v1 = query(a, b, k*2+1, l, (l + r) / 2);
	ll v2 = query(a, b, k*2+2, (l + r) / 2, r);
	return v1 + v2;
}
struct UnionFind {
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

	UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++) par[i] = i;
	}
	int size(int a) {
		return par[root(a)];
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

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = a * x + b * y;
	if (x > y) {
		ans = min({ ans,a * (x - y) + c * 2 * y,c * 2 * x });
	}
	else ans = min({ans, b * (y - x) + c * 2 * x, c * 2 * y});
	cout << ans << endl;
	return 0;
}