#include <iostream>
#include <string>
using namespace std;
int main()
{
	string S;
	char A;
	int N, K, i;
	cin >> N >> S >> K;
	A = S[K-1];
	for (i = 0; i < N; i++) {
		if (S[i] != A)
			S[i] = '*';
}
	cout << S;


}