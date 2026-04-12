#include <bits/stdc++.h>
using namespace std;
long solve(long* arr,vector<vector<long>>& dp1,vector<vector<long>>& dp2,int s,int e,int curr){
    if(s>e){
        return 0;
    }
    if(dp1[s][e]!=-1&&curr==1){
        return dp1[s][e];
    }
    if(dp2[s][e]!=-1&&curr==0){
        return dp2[s][e];
    }
    if(curr==0){
        dp2[s][e] = -arr[s]+solve(arr,dp1,dp2,s+1,e,1);
        dp2[s][e] = min(dp2[s][e],-arr[e]+solve(arr,dp1,dp2,s,e-1,1));
        return dp2[s][e];
    }
    else{
        dp1[s][e] = arr[s]+solve(arr,dp1,dp2,s+1,e,0);
        dp1[s][e] = max(dp1[s][e],arr[e]+solve(arr,dp1,dp2,s,e-1,0));
        return dp1[s][e]; 
    }
    
}
int main() {
    int n;
    cin>>n;
    long* arr = new long[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	vector<vector<long>> dp1(n,vector<long>(n,-1));
	vector<vector<long>> dp2(n,vector<long>(n,-1));
	
	cout<<solve(arr,dp1,dp2,0,n-1,1)<<'\n';
	return 0;
}