#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;
	vector<int64_t> A(N);
	for(int i = 0; i < N; i++) {
		cin >> A.at(i);
	}
	
	int64_t counter = 0;
	sort(A.begin(), A.end());
	if (N == 2) {
		counter = A.at(1) - A.at(0);
	}
	else if (N == 3) {
		counter = max(2*A.at(2)-A.at(0)-A.at(1), A.at(2)+A.at(1)-2*A.at(0));
	}
	
	else if(N % 2 == 0) {
		//int64_t counter1 = 0;
		//int64_t counter2 = 0;
		int M = N / 2;
		for (int i = M+1; i < N; i++) {
			counter = counter + 2*A.at(i);
		//	counter2 = counter2 - 2*A.at(i);	
		}
		for (int i = 0; i < M-1; i++) {
			counter = counter - 2*A.at(i);
		//	counter2 = counter2 + 2*A.at(i);
		}
		//counter = max(counter1+A.at(M)+A.at(M-1), counter2-A.at(M)-A.at(M-1));
		counter = counter + A.at(M) - A.at(M-1);
	}
	else {
		int64_t counter1 = 0;
		int64_t counter2 = 0;
		int M = (N-1) / 2;
		for (int i = M+1; i < N; i++) {
			counter1 = counter1 + 2*A.at(i);
			counter2 = counter2 - 2*A.at(N-1-i);	
		}
		for (int i = 0; i < M-1; i++) {
			counter1 = counter1 - 2*A.at(i);
			counter2 = counter2 + 2*A.at(N-1-i);
		}
		counter = max(counter1-A.at(M)-A.at(M-1), counter2+A.at(N-1-M)+A.at(N-1-(M-1)));
	}
	
	cout << counter << endl;

}

