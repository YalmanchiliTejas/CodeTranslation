#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cassert>
#include<vector>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>

using namespace std;
#define REP(i,m,n) for(int i=m;i<n;++i)
#define REPll(i,m,n) for(ll i=m;i<n;++i)
#define INF 10000000000000000
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define all(v) v.begin(),v.end()

int main() {
	int n;
	cin >> n;
	if (n == 3 || n == 5 || n == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	
	return 0;
}