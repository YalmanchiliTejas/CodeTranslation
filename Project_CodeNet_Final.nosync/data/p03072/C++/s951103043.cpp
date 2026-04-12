#include <bits/stdc++.h>
using namespace std;

int a[21], n, h, sol;
bool sees;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> h;
		a[i] = h;
		sees = true;
		for (int j = 0; j < i; j++){
			if (a[j] > h){
				sees = false;
				break;
			}
		}
		if (sees){
			sol += 1;
		}
	}
	cout << sol;
	return 0;
}