#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define ll long long
#define MOD_P 1000000007
using namespace std;

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < 2; i++) {
		if (str[i] != str[i + 1]) {
			printf("Yes");
			return 0;
		}
	}

	printf("No");

}
