#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
	int n, l;
	string str, str2;

	cin >> n ;
	cin >> str;
	cin >> l;
	str2 = str[l - 1];

	rep(i, n) {
		if (str[i] != str2[0]){
			str[i] = '*';
		}
	}

	cout << str;


	return 0;
}