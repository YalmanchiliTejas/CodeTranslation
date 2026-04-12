#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int main() {
	char c; cin >> c;
	char b[] = {'a', 'e', 'i', 'o', 'u'};
	
	bool flag = false;
	REP(i, 5) if (c == b[i]) flag = true;
	
	if (flag) puts("vowel");
	else puts("consonant");
	
	return 0;
}
