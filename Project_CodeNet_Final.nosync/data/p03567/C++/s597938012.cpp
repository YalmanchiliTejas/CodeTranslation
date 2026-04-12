#include<iostream>
#include<complex>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
typedef long long int llint;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
	char s[110];
	cin >> s;
	rep(i, strlen(s) - 1) {
		if (s[i] == 'A'&&s[i + 1] == 'C') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}