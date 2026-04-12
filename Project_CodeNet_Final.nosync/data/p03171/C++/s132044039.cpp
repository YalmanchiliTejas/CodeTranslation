#include <bits/stdc++.h>
using namespace std;
long long int helper(long long int dp[][3001],int A[],int i,int j){
    if(i>j){
        return 0;
    }
    if(i==j){
        return A[i];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j] = max(A[i]+min(helper(dp,A,i+1,j-1),helper(dp,A,i+2,j)),A[j]+min(helper(dp,A,i+1,j-1),helper(dp,A,i,j-2)));
    
}

int main() {
        int n;
        cin>>n;
        int A[n];
    	long long int total = 0;
        for(int i=0;i<n;i++){
            cin>>A[i];
            total+=A[i];
        }
        long long int dp[3001][3001];
        memset(dp,-1,sizeof(dp));
        long long int X =helper(dp,A,0,n-1);
    	long long int Y  = total-X;
    	cout<<X-Y<<endl;
	//code
	return 0;
}