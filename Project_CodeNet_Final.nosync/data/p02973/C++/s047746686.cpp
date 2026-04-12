#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <string>
#include <stack> // s.top()
#include <bitset>
#include <queue> // s.front()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define print(x) cout<<(x)<<endl
#define INF10 1001001001 
#define INF5 100000
#define EPS 1e-10

vector<int > A;
vector<int> seen;
int N;





int main() {
	cin >> N;
	A.assign(N, 0);
	seen.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] *= -1;
	}
	vector<int> b;
	b.push_back(A[0]);
	for (int i = 1; i < N; i++) {
		auto p = upper_bound(b.begin(), b.end(), A[i]);
		if (p == b.end()) {
			b.push_back(A[i]);
		}
		else {
			*p = A[i];
		}
	}
	cout << b.size() << endl;






	return 0;
}
