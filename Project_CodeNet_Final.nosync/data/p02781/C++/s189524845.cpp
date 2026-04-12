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


int main(){
	string s;
	int k;
	cin >> s >> k;
	int n = s.size()-1;
	int N = n;
	ll ans = 0;
	/*rip(i,k,0){
		ans *= (n-i)*9;
		ans /= i+1;
	}
	cout << ans << endl;*/
	while(n > -1 && k > 0){
		if(s[N-n] == '0'){
			n--;
			continue;
		}
		ll add = s[N - n] -'0'-1;
		rip(i,k-1,0){
			add *= (n-i)*9;
			add /= i+1;
		}
		//cout << n MM k MM add << endl;
		ans += add;
		add = 1;
		rip(i,k,0){
			add *= (n-i)*9;
			add/=i+1;
		}
		ans += add;
		k--;
		n--;
	}
	if(k==0) ans++;
	cout << ans << endl;
}