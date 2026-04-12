#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <math.h>
#include <utility>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(a) a.begin(),a.end()

int main() {
	int n; cin >> n;
	cout << 800 * n - 200 * (n / 15) << endl;
	return 0;
}