#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <bitset>
typedef long long ll;
typedef long double ld;

#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;


int main() {
	ll N;
	cin >> N;
	vector<ll>A(N);
	rep(i,N) {
		A[i] = i;
	}
	for (int i = 0; i < (1 << N);++i) {
		vector<ll>B;
		for (int j = 0; j < N;++j) {
			if (i&(1<<j)) {
				B.push_back(A[j]);
			}
		}
		cout << i << ":";
		for (int j = 0; j < B.size();++j) {
			cout << " " << B[j];
		}
		cout << endl;
	}
	return 0;
}
