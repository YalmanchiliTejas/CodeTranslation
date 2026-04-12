#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec; typedef pair<int, int> pi;
int dd[] = { 0, 1, 0, -1, 0 };


int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	cout << (((g * 10 + b) % 4 != 0) ? "NO" : "YES") << endl;
	return 0;
}
