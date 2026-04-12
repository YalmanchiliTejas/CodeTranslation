#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

int main(){
	int n;
	
	cin >> n;
	
	int sum = 800 * n;
	
	for (int i = n; i > 14; i-=15) sum -= 200;
	
	cout << sum << endl;
	
	return 0;
}