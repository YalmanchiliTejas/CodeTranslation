#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include<iomanip>

using namespace std;
#define ff(ii,nn,mm) for(int ii=nn;ii<mm;ii++)
#define i64 int64_t
#define tos(x) to_string(x)

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	deque<int> b;
	ff(i, 0, n) {
		cin >> a.at(i);
	}
	ff(i, 0, n) {
		if (n % 2 != i % 2) {
			b.push_front(a.at(i));
		}
		else {
			b.push_back(a.at(i));
		}
	}
	cout << b.at(0);
	ff(i, 1, n) {
		cout << " " << b.at(i);
	}
	return 0;
}
