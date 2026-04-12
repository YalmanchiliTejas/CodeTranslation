#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	int A_flag = 0;
	int B_flag = 0;

	cin >> S;

	for(int i = 0; i < 3; i++){
		if(S[i] == 'A')
			A_flag = 1;
		else
			B_flag = 1;
	}

	if(A_flag && B_flag)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}