#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<bitset>

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000

using namespace std;

int main(void) {
	int x, y, z;
	int total = 0;
	int count = 0;

	cin >> x >> y >> z;
	total += z;

	while (1) {
		if (x - total >= y+z) {
			total += y + z;
			count++;
		}
		else {
			break;
		}
	}
	cout << count << endl;

	return 0;
}