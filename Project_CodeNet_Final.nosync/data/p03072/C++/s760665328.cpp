#include <iostream>
using namespace std;
int main()
{
	int N, H[20],i,j,Ans = 1;
	
	cin >> N;
	for (i = N; i>0 ; i--)
		cin >> H[i];

	for (i = 1; i < N; i++) {
		Ans += 1;
		for (j = i + 1; j <= N; j++) {
			if (H[i] < H[j]) {
				Ans -= 1;
				break;
			}
		}
	}

	cout << Ans;
	return 0;
}