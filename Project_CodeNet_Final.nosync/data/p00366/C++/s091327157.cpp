#include <iostream>
#include <vector>
using namespace std;

int n, tmax = 0, d = 0;
int t[100000];
vector<int> dd;

int main()
{	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t[i];
		if (t[i] > tmax)
			tmax = t[i];
	}

	for (int i = 1; i <= tmax; i++) {
		if (tmax % i == 0)
			dd.push_back(i);
	}

	for (int i = 0; i < n; i++) {
		vector<int>::iterator itr = dd.begin();
		while (*itr < t[i])
			itr++;
		d += *itr - t[i];
	}

	cout << d << endl;

	return 0;
}

