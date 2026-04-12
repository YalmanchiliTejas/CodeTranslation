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
#include <stdio.h>

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

vector<vector<ll>> dp(4, vector<ll>(101));
int dpp[101];

int main(){
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	dpp[n] = 0; 
	rip(i,n,0){ 
		rip(j,k+1,0){
			dp[j][n-i-1] = dp [j][n-i];
		}
		rip(j,k,0){
			dp[j+1][n-i-1] += dp[j][n-i]*9;
		}
		if(s[i] == '0'){
			dpp[n-i-1] = dpp[n-i];
		}
		else{
			dpp[n-i-1] = dpp[n-i]+1;
			if(dpp[n-i] < k) dp[dpp[n-i]+1][n-i-1] += s[i]-'1';
			if(dpp[n-i] <= k) dp[dpp[n-i]][n-i-1] += 1;
		}
	}
	if(dpp[0]==k) dp[k][0]++;
	//vdeb(dp);
	cout << dp[k][0] << endl;
}