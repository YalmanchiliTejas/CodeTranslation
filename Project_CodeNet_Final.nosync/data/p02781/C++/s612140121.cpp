#include <iostream>
#include <vector>
#include <string>

using namespace std;


string N;
int K;

int main()
{
	cin >> N;
	cin >> K;
	
	int ans = 0;

	auto A = vector<int>(K+1,0);
	int B;

	A[0] = 1;
	A[1] = N[0] - '0' - 1;
	B = 1;

	for (unsigned i = 1; i < N.size(); i++) {
		auto Ad = vector<int>(K + 1, 0);
		int n = N[i] - '0';

		Ad[0] = 1;
		for (int j = 1; j <= K; j++) {
			Ad[j] += A[j - 1] * 9;
			Ad[j] += A[j];
		}

		if (n > 0) {
			if (B < K + 1) {
				Ad[B] += 1;
			}
			if (B < K) {
				Ad[B + 1] += n - 1;
			}
			B++;
		}
		A = Ad;
	}

	ans = A[K];
	if (B == K) { ans++; }


	cout << ans << endl;

	return 0;
}