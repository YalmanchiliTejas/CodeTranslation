//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <time.h>
#include <cassert>
#include <fstream>
#include <stdio.h>
#include<unordered_map>

typedef long long ll;
typedef std::pair<int, int> Pii;
typedef std::pair<long long, long long> Pll;
typedef std::pair<double, double> Pdd;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mapa make_pair
#define all(a) a.begin(), a.end()
#define MM << " " <<

template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }
template<typename T>
void vdeb(std::vector<T> &da) {
	for (int i = 0;i < da.size();i++) {
		if (i == da.size() - 1) std::cout << da[i];
		else std::cout << da[i] << ' ';
	}
	std::cout << std::endl;
}
template<typename T>
void vdeb(std::vector<std::vector<T>> &da) {
	for (int i = 0;i < da.size();i++) vdeb(da[i]);
	std::cout << std::endl;
}

using namespace std;

int n,m,ans= 0;
vector<vector<bool>> da(8, vector<bool>(8));

bool check(vector<int> &now){
	// vdeb(now);
	rip(i,n-1,0){
		if(da[now[i]][now[i+1]] == 0) return false;
	}
	return true;
}

void rec(vector<int> &now, vector<bool> &ju, int next){
	if(next == n){
		// vdeb(now);
		if(check(now)) ans++;
		return;
	}
	rip(i,n,0){
		if(ju[i]){
			ju[i] = false;
			now[next] = i;
			rec(now, ju, next+1);
			ju[i] = true;
		}
	}
	return;
}

int main(){
	cin >> n >> m;
	rip(i,m,0){
		int a,b;cin >> a >> b;
		a--;b--;
		da[b][a] = 1;
		da[a][b] = 1;
	}
	vector<int> now(n);
	vector<bool> ju(n, true);
	ju[0] = false;
	rip(i,n,0) now[i] = i;
	// next_permutation
	rec(now, ju, 1);
	// vdeb(da);
	cout << ans << endl;
}