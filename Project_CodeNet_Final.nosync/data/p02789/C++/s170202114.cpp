#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <bitset>
#include <ctime>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <sstream>
#pragma comment(linker, "/STACK:256000000")
using namespace std;

#define in(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)
#define forn(i, n) for (int i = 0; i < n; i++)
#define endl '\n'
#define mp make_pair

typedef long long ll;
typedef long double ld;

int main()
{
	//in("input.txt");
	//out("output.txt");
	srand(1373737);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	if (n == m)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}