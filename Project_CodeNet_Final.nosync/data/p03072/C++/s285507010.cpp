#include <bits/stdc++.h>

using namespace std;

int main() {
	// input

	int num; cin >> num;
	vector<int> Height(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> Height[i];
	}


	//compute
	int ans = 0;
	for (int i = 0; i < num; ++i)
	{
		bool is_candidate = true;

		for (int j = 0; j < i; ++j)
		{
			
			if (Height[j] > Height[i])
			{
				is_candidate = false;
				break;
			}

		}


		if (is_candidate)
		{
			++ans;/* code */
		}


	}

	cout << ans << endl;
}