#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
using namespace std;
using ll =long long;
int main() {
	string S;
	cin >> S;
	for (int i=0; i < S.size()-1; i++) {
		if (S[i] != S[i + 1]) {

			cout << "Yes";
			return 0;
		}


	}
	cout << "No";

}