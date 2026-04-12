//Atcoder 177C
#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

int MOD=1000000007;

int32_t main(){
	int n;
	cin >> n;
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sum=(sum+arr[i])%MOD;
	}
	int answer=0;
	for(int i=0;i<n;i++){
		sum=(sum-arr[i]);
		if(sum<0) sum+=MOD;
		answer=(answer+(arr[i]*sum)%MOD)%MOD;
	}
	cout << answer << endl;
	return 0;
}