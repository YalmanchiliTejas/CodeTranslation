#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cassert>

#define INFLL 2000000000000000000
#define INF 2000000000
#define MOD 1000000007
#define PI acos(-1.0)

typedef std::pair <int, int> pii;
typedef long long ll;
typedef std::vector <ll> vll;

using namespace std;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);	
	string s;
	cin >> s;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == 'A' && s[i + 1] == 'C') {
			cout << "Yes" << endl;
			return 0;
		}	
	}
	cout << "No" << endl;
	return 0;
}