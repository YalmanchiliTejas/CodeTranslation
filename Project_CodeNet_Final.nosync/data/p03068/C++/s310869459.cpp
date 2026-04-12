#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	string S;
	cin >> S;

	int K;
	cin >> K;

	char target = S[K - 1];
	for (int i = 0; i < N; i++) {
		if (S[i] != target)
			S[i] = '*';
	}
	
	cout << S << endl;

	return 0;
}
