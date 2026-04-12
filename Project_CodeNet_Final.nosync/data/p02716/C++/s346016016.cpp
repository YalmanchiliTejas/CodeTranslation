// #include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <climits>
#include <string>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
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

const ll NM = 202000;

ll dp[NM][3][2];

int main(){
	int n; cin >> n;
	vector<ll> da(n);
	rip(i,n,0) cin >> da[i];
	rip(i,6,0) dp[0][i%3][i/2] = LLONG_MIN/2;
	dp[0][1][0] = 0;
	rip(i,n,0){
		if((i+1)&1){
			dp[i+1][2][1] = da[i] + dp[i][1][0];
			dp[i+1][1][1] = da[i] + dp[i][0][0];
			dp[i+1][0][1] = LLONG_MIN/2;
			dp[i+1][2][0] = max(dp[i][2][0], dp[i][2][1]);
			dp[i+1][1][0] = max(dp[i][1][0], dp[i][1][1]);
			dp[i+1][0][0] = max(dp[i][0][0], dp[i][0][1]);
		}
		else{
			dp[i+1][2][1] = da[i] + dp[i][2][0];
			dp[i+1][1][1] = da[i] + dp[i][1][0];
			dp[i+1][0][1] = da[i] + dp[i][0][0];
			dp[i+1][2][0] = LLONG_MIN/2;
			dp[i+1][1][0] = max(dp[i][2][0], dp[i][2][1]);
			dp[i+1][0][0] = max(dp[i][1][0], dp[i][1][1]);
 		}
	}
	cout << max(dp[n][1][0], dp[n][1][1]) << endl;
}