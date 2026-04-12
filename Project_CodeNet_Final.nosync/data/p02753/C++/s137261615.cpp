

#include <iostream>
#include <vector>
#include <string>


using namespace std;

string S;

int main()
{

	cin >> S;

	bool ans = true;

	ans = !(S[0] == S[1] && S[0] == S[2]);


	cout << (ans?"Yes":"No")<< endl;

	return 0;
}

