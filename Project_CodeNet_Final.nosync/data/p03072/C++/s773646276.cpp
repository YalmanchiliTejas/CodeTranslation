#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int k = 0,mh = 0;
	for(int i = 0;i < n;i++)
	{
		int h;
		cin >> h;
		if(h >= mh)
		{
			k++;
			mh = h;;
		}
	}
	cout << k << endl;
	return 0;
}
