#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<long> A(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	long ans = 0;
	if(N % 2){
		long ans1 = 0, ans2 = 0;
		for(int i=0;i<N / 2;i++){
			ans1 -= 2 * A[i];
		}
		ans1 += A[N / 2];
		ans1 += A[N / 2 + 1];
		for(int i=N / 2+2;i<N;i++){
			ans1 += 2 * A[i];
		}
		for(int i=0;i<N / 2 - 1;i++){
			ans2 -= 2 * A[i];
		}
		ans2 -= A[N / 2 - 1];
		ans2 -= A[N / 2];
		for(int i=N / 2+1;i<N;i++){
			ans2 += 2 * A[i];
		}
		ans = max(ans1, ans2);
	}
	else{
		for(int i=0;i<N / 2 - 1;i++){
			ans -= 2 * A[i];
		}
		ans -= A[N / 2 - 1];
		ans += A[N / 2];
		for(int i=N / 2+1;i<N;i++){
			ans += 2 * A[i];
		}
	}
	cout << ans << endl;
}