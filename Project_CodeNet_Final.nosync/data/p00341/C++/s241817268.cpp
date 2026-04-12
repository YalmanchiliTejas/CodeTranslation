#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n[12];
	int e[101] = {};
	for (int i = 0; i < 12; ++i) {
		cin >> n[i];
		e[n[i]] += 1;
	}
	for (int i = 0; i < 101; ++i) {
		
		if (e[i] % 4 == 0) {

			if (i == 100) {
				cout << "yes" << endl;
			}
		}
		else { cout << "no" << endl; break; }
	}
}
