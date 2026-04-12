#include <iostream>
#include <vector>
#include <limits.h>


using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long long int> a;
	long long int wk;
	for (int i = 0; i < n; i++) {
		cin >> wk;

		a.push_back(wk);

	}

	vector<long long int> sub;
	long long int mini = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (a[i] <= mini) {
			sub.push_back(a[i]);
			mini = a[i];
		}
		else {
			for (int j = 0; j < sub.size(); j++) {
				if (a[i] > sub[j]) {
					sub[j] = a[i];
					if (j == sub.size() - 1)mini = sub[j];


					break;
				}
			}
		}
	}

	int ans;
	ans = sub.size();

	cout << ans << endl;

	return 0;



}

