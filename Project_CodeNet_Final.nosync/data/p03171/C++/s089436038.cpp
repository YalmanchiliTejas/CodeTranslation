#include<bits/stdc++.h>
using namespace std;
#define int long long
int *arr;
int memo[3000][3000][2];

// TIME COMPLEXITY = O(N^2)
// SPACE COMPLEXITY = O(N^2)

// find will return the required ans,  turn is 0 or 1 denoting taro and jiro resp

int find(int start, int end, int turn){
	
	// base case
	if(start == end){
		if(turn==0) return arr[start];
		else return -1*arr[start];
	}
	
	if(memo[start][end][turn] != -1) 
		return memo[start][end][turn];
	int ans;

	if(turn==0){
		int a = arr[start] + find(start+1,end,turn^1);
		int b = arr[end] + find(start, end-1, turn^1);
		ans = max(a,b);
	}
	else{
		int a = -1*arr[start] + find(start+1, end, turn^1);
		int b = -1*arr[end] + find(start, end-1, turn^1);
		ans = min(a, b);
	}

	memo[start][end][turn] = ans;
	return ans;
}

signed main(){
	
	int n;
	cin >> n;
	arr = new int[n];
	for(int i=0;i<n;i++) cin >> arr[i];

	for(int i=0;i<3000;i++){
		for(int j=0;j<3000;j++){
			memo[i][j][0] = -1;
			memo[i][j][1] = -1;
		}
	}

	cout << find(0, n-1, 0) << endl;
	

	return 0;
}