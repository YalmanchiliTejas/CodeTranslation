#include <iostream>
#include <stdio.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <bitset>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
using namespace std;

int main(void)
{
	int n; cin >> n;
	map<char, int> count; rep(i, 0, 26)count['a' + i] = 50;
	rep(i, 0, n) {
		string tmp; cin >> tmp;
		map<char, int> tmp_count;
		rep(j, 0, tmp.length())tmp_count[tmp[j]]++;
		rep(j, 0, 26)count['a' + j] = min(count['a' + j], tmp_count['a' + j]);
	}
	rep(i, 0, 26) {
		rep(j, 0, count['a' + i])cout << (char)('a' + i);
	}
	cout << endl;

	return 0;
}
