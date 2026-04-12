#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> A;


int dp[10100];

int solve(){
	vector<int> ansv;
	long long ans=0;

	sort(A.begin(),A.end());

	int small = 0;
	int large = N-1;

	ans += A[N-1]-A[0];
	for(int i=0; i<N/2-1; i++){
		ans += abs( A[large] - A[small+1] );
		ans += abs( A[small] - A[large-1] );		
		small++; large--;
	}

	if(N%2==1) ans+=max(abs(A[N/2]-A[N/2+1]), abs(A[N/2]-A[N/2-1]));

	cout << ans << endl;
	return 0;
}


int main(){
	cin >> N;
	A.resize(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}

	solve();
	return 0;
}
