#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> H(N);
	for (int i = 0; i < N; i++) cin >> H.at(i);

	int ANS = 1;
	while(N > 1){
		for (int i = N - 1; i > 0; i--) {
			if (H.at(N - 1) >= H.at(i - 1)) {
				if (i == 1) ANS++;
			}else break;
		}
		N--;
	}
	cout << ANS << endl;
}