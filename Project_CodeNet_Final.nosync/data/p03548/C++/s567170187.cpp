#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	cout << (x - z) / (y + z) << endl;
	return 0;
}