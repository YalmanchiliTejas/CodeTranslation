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
typedef long long ll;
typedef long double ld;


#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;
ll S[1000] = { 0 };
ll N,M,Q;


int main() {
	cin >> N;
	vector<ll>A(N);
	rep(i, N)cin >> A[i];
	cin >> Q;
	rep(i, Q) {
		ll k;
		cin >> k;
		vector<ll>::iterator a=lower_bound(A.begin(), A.end(), k);
		cout << distance(A.begin(),a)  << endl;
	}
	return 0;
}



