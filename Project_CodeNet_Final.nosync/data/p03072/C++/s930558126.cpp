#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <ccomplex>
#include <unordered_map>
#include <cstring>
#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <tuple>
#include <iomanip>

using namespace std;
#define MAX 1LL << 60

typedef long long ll;

#define rep(i, s, e) for(ll i = s; i < e; i++)
#define repR(i, s, e) for(ll i = s; i > e; i--)
#define reft0(i, j) setfill('0') << setw(i) << j

template<class T> inline bool chMax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chMin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main(){
	ll N;
	vector<ll> H;
	cin >> N;

	rep(i, 0, N){
		ll temp;
		cin >> temp;
		H.push_back(temp);
	}
	ll start = H[0];
	ll cnt = 1;
	rep(i, 1, N){
		if (H[i] >= start){
			cnt++;
			start = H[i];
		}
	}
	cout << cnt << endl;

	return 0;
}
