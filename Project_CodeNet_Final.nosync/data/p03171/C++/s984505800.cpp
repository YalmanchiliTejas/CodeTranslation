#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll memo[3001][3001];

ll dequeMax(int i,int j, vector<ll>& arr){
	if(i == j){
		return arr[i];
	}
	if(memo[i][j] != -1) return memo[i][j];

	return memo[i][j] = max(arr[i] - dequeMax(i+1,j,arr), arr[j] - dequeMax(i,j-1,arr));
}


int main(){
	ll N;
	cin>>N;
	vector<ll>arr(N);

	for(ll i = 0; i < N; ++i){
		cin>>arr[i];
	}
	memset(memo, -1, sizeof(memo));
	cout<<dequeMax(0,arr.size()-1,arr);
}