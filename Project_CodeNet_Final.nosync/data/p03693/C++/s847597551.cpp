#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <math.h>
using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(a) a.begin(),a.end()

int main() {
	int hoge, g, b;
	cin >> hoge >> g >> b;
	if ((10 * g + b) % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
