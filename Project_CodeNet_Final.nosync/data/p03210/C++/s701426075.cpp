#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define IN cin >>
#define OUT cout <<
#define INF 999999999


int main() {
	int x;
	IN x;

	if (x == 3) {
		OUT "YES";
		goto A;
	}
	if (x == 5) {
		OUT "YES";
		goto A;
	}
	if (x == 7) {
		OUT "YES";
		goto A;
	}
	OUT "NO";
A:

	return 0;
}