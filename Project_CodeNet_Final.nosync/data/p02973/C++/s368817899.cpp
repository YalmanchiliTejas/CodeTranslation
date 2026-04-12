#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair
int N, A[100000];
vector<int> dp;
int main(){
	cin >> N;
	for(int i=0; i<N; i++) cin >> A[i];
	reverse(A, A+N);

	dp.resize(N);
	for(int i=0; i<N; i++) dp[i] = INT_MAX;
	for(int i=0; i<N; i++){
		*lower_bound(dp.begin(), dp.end(), A[i]+1) = A[i];
	}
	cout << lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin() << endl;
}
