#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
	int n;
	cin >> n;

	VI ans(n);
	if (n % 2 == 0){
		REP(i,n){
			int j = i/2;
			if (i % 2 == 0){
				cin >> ans[n/2+j];
			}else{
				cin >> ans[n/2-1-j];
			}
		}
	}else{
		REP(i,n){
			int j = i/2;
			if (i % 2 == 0){
				cin >> ans[n/2-j];
			}else{
				cin >> ans[n/2+1+j];
			}
		}
	}
	REP(i,n) printf("%d ", ans[i]);
	cout << endl;
	return 0;
}