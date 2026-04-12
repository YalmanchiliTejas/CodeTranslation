#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int main(){
	int num, a, b, c; cin >> a >> b >> c;
	num = 100 * a + 10 * b + c;
	if(num % 4) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}