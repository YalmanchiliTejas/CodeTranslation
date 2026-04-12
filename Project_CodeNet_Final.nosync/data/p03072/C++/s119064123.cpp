#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> h;
	int n;
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		h.push_back(temp);
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		int ok = 1;
		for (int j = 0; j < i; j++) {
			if (h[i] < h[j])
				ok = 0;
		}
		if (ok)
			count++;
	}
	cout << count;
}