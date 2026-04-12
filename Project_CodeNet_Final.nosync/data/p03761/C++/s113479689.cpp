#include <iostream>
#include <string>
#include <vector>
#define N 12
using namespace std;
int main() {
	string ans;
	int s[30][50];
	int min;
	int n;
	int l;
	cin >> n;
    
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 30; j++) {
			s[j][i] = 0;
		}
	}

	for (int i = 0; i < n;i++) {
		cin >> ans;
		l = ans.length();
		for (int j = 0; j < l;j++) {
			s[('a' - ans[j])*-1][i] ++ ;
		}
	}
    
	for (int i = 0; i < 30;i++) {
		min = s[i][0];
		for (int j = 1; j < n; j++) {
			if (min > s[i][j]) {
				min = s[i][j];
			}
		}
		while (min > 0) {
			cout << (char)('a' + i);
			min--;
		}
	}
	cout << endl;


	return 0;
}
