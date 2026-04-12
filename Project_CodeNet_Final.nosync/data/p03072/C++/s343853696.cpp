#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n,sum=0,max=0;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> h[i];
		if (max <= h[i])
		{
			sum++;
			max = h[i];
		}
	}

	cout << sum << endl;
	return 0;
}