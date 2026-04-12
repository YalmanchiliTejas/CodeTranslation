#include <iostream>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef vector <ll> vl;
typedef set <ll> sl;
typedef vector <pair <ll, ll>> vll;
typedef map <string, int> msi;


int main() {
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	if ((10 * b + c) % 4 == 0)
		cout << "YES";
	else
		cout << "NO";


	return 0;
}
