#include <bits/stdc++.h>
using namespace std;

//ifstream fin("date.in");
//ofstream gout("date.out");

const int NMax = 1e6 + 5;
const int mod = 1e9 + 7;

int main()
{
	string S;

	cin >> S;
	int n = S.size();

	for(int i = 0; i < n - 1; ++i) {
		if(S[i] == 'A' && S[i + 1] == 'C'){
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";

	return 0;
}