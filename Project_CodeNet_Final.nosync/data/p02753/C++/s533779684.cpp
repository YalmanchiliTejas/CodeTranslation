#include <bits/stdc++.h>
using namespace std;

int main() {
	string inp;
	cin >> inp;
	
	int a = 0, b = 0;
	
	for(auto i : inp) {
		if(i == 'A')
			++a;
		else ++b;
	}
	if(a > 0 && b > 0)
		puts("Yes");
	else puts("No");
}