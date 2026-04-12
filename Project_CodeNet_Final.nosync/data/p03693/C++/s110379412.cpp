#include<iostream>
#include<algorithm>
#include <string>
#include<cstdio>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
using namespace std;
typedef long long ll;

int main()
{
	int a, b, c; cin >> a >> b >> c;
	if ((100 * a + 10 * b + c) % 4 == 0) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	return 0;
}