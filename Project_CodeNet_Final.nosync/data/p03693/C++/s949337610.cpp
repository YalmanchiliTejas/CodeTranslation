#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <string>
#include <set>
#include <bitset>

using namespace std;
#define ff(ii,nn,mm) for(int ii=nn;ii<mm;ii++)
#define i64 int64_t
#define tos(x) to_string(x)


int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((b * 10 + c) % 4 == 0) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
