#include<iostream>
#include<math.h>
#include<complex>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include <cstdint>
#include<string.h>

typedef unsigned long long ll;

using namespace std;

int main() {
	int n;
	int i = 0;
	cin >> n;
	char s[1000];
	for (i = 0; i < n; i++) {
		cin >> s[i];
	}
	int k;
	cin >> k;


	
	
	for (i = 0; i < n; i++) {
		if (s[k-1] != s[i]) {
			s[i] = '*';
		}

	}
	for (i = 0; i < n; i++) {
		cout << s[i] ;
	}
}

