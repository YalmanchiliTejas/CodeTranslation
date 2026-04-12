#include <iostream>
#include <vector>

using namespace std;



int main() {
	int n;
	//vector<int> h;

	cin >> n;

	int count = 0;
	int highest = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		//h.push_back(x);

		if (x >= highest)
		{
			count += 1;
			highest = x;
		}
	}

	cout << count << endl;
}

