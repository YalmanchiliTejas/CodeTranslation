#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;
typedef long long int lli;

int main() {
	lli N;
	vector<lli> A;

	cin >> N;
	for(lli i=0; i<N; i++) {
		lli a;
		cin >> a;
		A.push_back(a);
	}

	sort(A.begin(), A.end());

	if(N%2 == 0) {
		lli sum = 0;
		for(lli i=0; i<N; i++) {
			if(i+1 == N/2) {
				sum -= A[i];
			} else if(i+1 == N/2+1){
				sum += A[i];
			} else if(i+1 < N/2){
				sum -= 2 * A[i];
			} else {
				sum += 2 * A[i];
			}
		}
		cout << sum << endl;
	}  else {
		lli sum1 = 0;
		lli sum2 = 0;
		for(lli i=0; i<N; i++) {
			if(i+1 == (N+1)/2) {
				sum1 -= A[i];
			} else if(i+1 == (N-1)/2){
				sum1 -= A[i];
			} else if(i+1 < (N+1)/2){
				sum1 -= 2 * A[i];
			} else {
				sum1 += 2 * A[i];
			}
			if(i+1 == (N+1)/2) {
				sum2 += A[i];
			} else if(i+1 == (N+3)/2) {
				sum2 += A[i];
			} else if(i+1 < (N+1)/2) {
				sum2 -= 2 * A[i];
			} else {
				sum2 += 2 * A[i];
			}
		}
		cout << max(sum1, sum2) << endl;
	}


}
