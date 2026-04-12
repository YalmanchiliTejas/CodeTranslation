#include<bits/stdc++.h>
using namespace std;

long long f(vector<long long> &arr, int i, int j,
            bool taro, vector<vector<long long> > &dp) {
	if(i+1==j) {
    	// last two elements left
      	if(taro) {
	      	return max(arr[i], arr[j]);      	
        }
      	else {
        	return min(arr[i], arr[j]);
        }
    }
  	if(dp[i][j]!=0)
      	return dp[i][j];
  
  	if (taro)
	  	dp[i][j] = max(arr[i] + f(arr,i+1, j, !taro, dp),
                   arr[j] + f(arr,i, j-1, !taro, dp));
  	else
      	dp[i][j] = min(f(arr,i+1, j, !taro, dp),
                   f(arr,i, j-1, !taro, dp));
  	return dp[i][j];
}

int main() {
  	int N;
	cin>>N;
  	vector<long long> arr(N, 0);
	long long sum=0;
  	for(int i=0;i<N;i++) {
      	cin>>arr[i];
      	sum += arr[i];
    }
  
    if(N==1) {
      	cout<< arr[0];
    	return 0;
    }
  	long long X,Y;
  	vector<vector<long long> > dp(N, vector<long long>(N,0));

  	f(arr, 0, N-1, true, dp);
  	X = dp[0][N-1];
  	Y = sum-X;
  	//cout<<"X "<<X<<endl;
  	//cout<<"Y "<<Y<<endl;
  	
  	cout<<X-Y<<endl;
  
  	return 0;
}