#include <iostream>
#include <string>

using namespace std;

int N;
string S;
int K;

int main()
{
	cin >> N >> S >> K;
	for (int i=0; i<S.length(); i++) if (S[i]!=S[K-1]) S[i]='*';
	cout << S;
	return 0;
}