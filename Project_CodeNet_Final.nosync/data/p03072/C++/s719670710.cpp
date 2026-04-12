#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 0;
	int top = 0;
	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		if (top <= h)
		{
			count++;
			top = h;
		}
		else {
			//cout << count;
			//return 0;
		}
	}
	cout << count;
}