#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;





int main()
{
	int a[7];
	int n;
	int sum;
	string ind[10000];
	while (cin >> n,n) {
		for (int i = 0; i < n; i++) {
			cin >> ind[i];
		}
		for (int i = 1; i < 7; i++) {
			a[i] = i;
		}
		sum = 1;
		for (int i = 0; i < n; i++) {
			if (ind[i] == "North") {
				swap(a[1], a[2]);
				swap(a[2], a[6]);
				swap(a[6], a[5]);
			}
			else if (ind[i] == "East") {
				swap(a[1], a[4]);
				swap(a[4], a[6]);
				swap(a[6], a[3]);
			}
			else if (ind[i] == "West") {
				swap(a[1], a[3]);
				swap(a[3], a[6]);
				swap(a[6], a[4]);
			}
			else if (ind[i] == "South") {
				swap(a[1], a[2]);
				swap(a[1], a[5]);
				swap(a[5], a[6]);
			}
			else if (ind[i] == "Right") {
				swap(a[3], a[2]);
				swap(a[3], a[5]);
				swap(a[5], a[4]);
			}
			else if (ind[i] == "Left") {
				swap(a[2], a[3]);
				swap(a[2], a[4]);
				swap(a[4], a[5]);
			}
			sum += a[1];
		}

		cout << sum << endl;
	}




}