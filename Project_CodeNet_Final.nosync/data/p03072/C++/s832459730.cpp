#include <iostream>
#include <ostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 1000000;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int maxh = a[0];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxh <= a[i]) {
			count++;
			maxh = a[i];
		}
	}
	cout << count << endl;
}