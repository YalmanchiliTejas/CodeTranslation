#include <iostream>
#include<algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	char c[11];
	int n, k;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	cin >> k;
	for (int i = 1; i <= n; i++) {
		if (c[i] == c[k])cout << c[k];
		else cout << "*";
	}
	cout << endl;
}