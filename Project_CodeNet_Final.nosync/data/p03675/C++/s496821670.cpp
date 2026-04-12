#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> even, odd;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (i % 2 == 0) even.push_back(a);
		else odd.push_back(a);
	}
	if (n % 2 == 0) {
		for (int i = odd.size() - 1; i >= 0; i--) {
			cout << odd[i] << " ";
		}
		for (int i = 0; i < even.size(); i++) {
			if (i == even.size() - 1) cout << even[i];
			else cout << even[i] << " ";
		}
	}
	else {
		for (int i = even.size() - 1; i >= 0; i--) {
			cout << even[i] << " ";
		}
		for (int i = 0; i < odd.size(); i++) {
			if (i == odd.size() - 1) cout << odd[i];
			else cout << odd[i] << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}