#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<set>
#include<numeric>
#include<functional>
#include<unordered_map>
#include<cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	vector<int> b;
	for (int i = 0; i < N; i++) {
		if (i % 2 == N % 2) {
			b.push_back(a[i]);
		}
		else {
			b.insert(b.begin(), a[i]);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << b[i] << " ";
	}
	cout << endl;

}
