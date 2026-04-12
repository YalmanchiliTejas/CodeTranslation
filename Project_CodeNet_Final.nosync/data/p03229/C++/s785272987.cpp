#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A;

	int sort_A[N];

	for (int n=0; n<N; n++){
		int a;
		cin >> a;
		A.push_back(a);
	}

	sort(A.begin(), A.end());

	if (N % 2 == 0){
		for (int n=0; n<N; n++){
			if (n % 2 == 0){
				sort_A[n] = A[(N - n)/2 - 1];
			}
			else{
				sort_A[n] = A[N - (1+n)/2];
			}
		}
	}
	else{
		if (A[(N+1)/2]- A[(N-1)/2] < A[(N-1)/2] - A[(N-3)/2]){
			sort(A.begin(), A.end(), greater<int>());
		}

		sort_A[0] = A[(N-1)/2];
		for (int n=1; n<N; n++){
			if (n % 2 == 0){
				sort_A[n] = A[n/2 - 1];
			}
			else{
				sort_A[n] = A[N - (1+n)/2];
			}
		}
	}

	long long ans = 0;

	for (int n=1; n<N; n++){
		ans += abs(sort_A[n] - sort_A[n-1]);
	}

	cout << ans << endl;
}