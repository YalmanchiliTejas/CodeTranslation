//be naame khodaa

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#define fi first
#define se second
#define rep(i, x, n) for (int i = x; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> VI;

int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for (int i = 0; i+1 < s.length(); i++)
		if (s[i] == 'A' && s[i+1] == 'C')
			return (cout << "Yes\n"), 0;
	cout << "No\n";
	return 0;
}