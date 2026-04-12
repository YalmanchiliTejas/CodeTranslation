#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>

#include<stack>
#include<queue>
#include<time.h>
#include<set>
#include<map>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
const ll mod = 998244353;


ll N,X[200001],x[200001];


int main() {
	cin >> N;
	FOR(i, 0, N) {
		cin >> X[i];
		x[i] = X[i];
	}
	sort(X, X + N);

	FOR(i, 0, N) {

		if (x[i] <= X[N / 2 - 1]) {
			cout << X[N / 2 ] << endl;
		}
		else cout << X[N / 2-1] << endl;

	}

	return 0;
}