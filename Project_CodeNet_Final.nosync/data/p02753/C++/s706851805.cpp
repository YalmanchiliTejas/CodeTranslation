#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	bool ans = false;
	if (S[0] != S[1]) ans = true;
	if (S[1] != S[2]) ans = true;
	if (S[2] != S[0]) ans = true;
	printf(ans ? "Yes" : "No");

	return 0;
}
