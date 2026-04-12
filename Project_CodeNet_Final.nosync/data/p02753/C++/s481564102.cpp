#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;

	if (S[0] != S[1]) {
		printf("Yes\n");
		return 0;
	}

	if (S[0] != S[2]) {
		printf("Yes\n");
		return 0;
	}

	printf("No\n");
	return 0;
}