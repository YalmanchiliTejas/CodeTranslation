#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int N, K;
	string S;

	cin >> N;
	cin >> S;
	cin >> K;

	char key = S[K-1];
	//cout << "key:" << key << endl;

	for (int i = 0; i < N; i++) {
		if (key == S[i]) {

		}
		else {
			S.replace(i, 1,"*");
		}
	}
	cout << S;
	return 0;
}