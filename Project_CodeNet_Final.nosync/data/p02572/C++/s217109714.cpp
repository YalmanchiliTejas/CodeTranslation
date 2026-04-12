#include<iostream>
#include<string>
#include<stdio.h>
#include<cctype>
#include<algorithm>
#include<climits>
#include<cmath>
#include<map>
#include<vector>
#define INF INT_MAX
using namespace std;

int N;
int mod = 1000000007;
long long sum;
long ans;

int main(){
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++){
		cin >> A[i];
		sum += A[i];
		sum %= mod;
	}
	
	for (int i = 0; i < N; i++){
		sum -= A[i];
		if (sum < 0)sum += mod;
		ans += A[i] * sum;
		ans %= mod;
	}

	cout << ans << endl;

	return 0;
}