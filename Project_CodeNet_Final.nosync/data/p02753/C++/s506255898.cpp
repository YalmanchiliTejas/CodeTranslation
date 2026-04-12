#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include <random>
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	string S;

	cin >> S;

	if (S[0] == S[1] && S[1] == S[2]) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}

}