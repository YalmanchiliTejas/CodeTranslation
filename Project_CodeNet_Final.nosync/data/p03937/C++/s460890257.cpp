//#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <numeric>
#include<bitset>

using namespace std;
#define modd 1000000007


typedef pair<long long, long long> pl;



#define ll long long




/*
class UnionFind {
public:
	vector <ll> par; 
	vector <ll> siz;
	vector <ll> gr;

	// Constructor
	UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) ,gr(sz_){
		for (ll i = 0; i < sz_; ++i) par[i] = i; 
	}
	void init(ll sz_) {
		par.resize(sz_);
		siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
		for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
	}

	// Member Function
	// Find
	ll root(ll x) { // 根の検索
		while (par[x] != x) {
			x = par[x] = par[par[x]]; // x の親の親を x の親とする
		}
		return x;
	}

	// Union(Unite, Merge)
	bool merge(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;

		// merge technique（データ構造をマージするテク．小を大にくっつける）
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}



	bool issame(ll x, ll y) { // 連結判定
		return root(x) == root(y);
	}

	ll size(ll x) { // 素集合のサイズ
		return siz[root(x)];
	}


};*/


long long N, M, K, a, b, c, d,e, H, W;
long long A[100][2005] = {};
long long B[200005] = {};
long long C[200005] = {};
long long BB[200005] = {};
long long CC[200005] = {};
bool f, ff;
string S[2];
set <long long>sll;
pl bufpl;
vector <long long>vl[100005];
vector <pl>vpl[20];
vector <string> vs[20];
set<ll> llset;

struct ST
{
	long long Kati;
	int bangou;

	bool operator<(const ST& another) const
	{
		return Kati < another.Kati;//比較
	};

};



vector <ST> vst;
ST st[200005];
ST bufst;
bitset<5000> bits;

char ch[100][100];

int main() {


	cin >> H>>W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> ch[i][j];
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = W-1; j >=0; j--) {
			if (ch[i][j] == '#') {
				B[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j <W; j++) {
			if (ch[i][j] == '#') {
				BB[i] = j;
				break;
			}
		}
	}

	for (int j = 0; j < W; j++) {
		for (int i = H-1; i >=0; i--) {
			if (ch[i][j] == '#') {
				C[j] = i;
				break;
			}
		}
	}

	for (int j = 0; j < W; j++) {
		for (int i = 0; i <H; i++) {
			if (ch[i][j] == '#') {
				CC[j] = i;
				break;
			}
		}
	}

	f = true;

	for (int i = 0; i < H; i++) {
		for (int j = i + 1; j < H; j++) {
			if (BB[j] < B[i]) {
				f = false;
			}
		}
	}

	for (int i = 0; i < W; i++) {
		for (int j = i + 1; j < W; j++) {
			if (CC[j] < C[i]) {
				f = false;
			}
		}
	}
	
	if (f) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;

}
