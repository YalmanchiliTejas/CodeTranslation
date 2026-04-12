#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <stack>

using namespace std;

typedef long long LL;
#define FAST ios::sync_with_stdio(false);
const int MaxN = 105;
int main()
{
	int n ,m ,x , ans;
	cin >> n;
	m = n % 15;
	m = (n - m) / 15;
	ans = n * 800 - m * 200;
	cout << ans << endl;
	return 0;
	}