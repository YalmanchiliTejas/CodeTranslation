#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> mountains(n);
	for (int i = 0; i < n; i++)
	{
		cin >> mountains.at(i);
	}
	
	int maxheight = mountains.at(0);
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		if (maxheight <= mountains.at(i))
		{
			ans++;
			maxheight = mountains.at(i);
		}
		
	}
	cout << ans << endl;
}