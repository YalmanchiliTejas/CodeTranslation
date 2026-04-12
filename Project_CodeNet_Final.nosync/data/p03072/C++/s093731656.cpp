#include <iostream>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	int h[n + 1];
	for (int i = 1; i <= n; i++) cin >> h[i];
	int count = 0;
	for (int i = 1; i <= n; i++)
		{
			bool c = 1;
			for (int j = 1; j < i; j++)
				if (h[i] < h[j]) c = 0;
			if (c) count++;
		}
	cout << count;
}
