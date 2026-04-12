#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector<int> A(N);
	for(int i=0; i<N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());

	vector<int> M(N), W(N);
	for(int i=0; i<N; i++){
		if(i%2 == 0){
			M[i] = -2;
			W[i] = 2;
		}
		else{
			M[i] = 2;
			W[i] = -2;
		}
	}
	M[0] -= M[0]/2;
	M[N-1] -= M[N-1]/2;
	W[0] -= W[0]/2;
	W[N-1] -= W[N-1]/2;

	sort(M.begin(), M.end());
	sort(W.begin(), W.end());

	long long sumM, sumW;
	sumM = sumW = 0;
	for(int i=0; i<N; i++){
		sumM += 1LL * A[i] * M[i];
		sumW += 1LL * A[i] * W[i];
	}

	cout << max(sumM, sumW) << endl;

	return 0;
}
