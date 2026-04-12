#include<bits/stdc++.h>
using namespace std;
vector <long long int> arr,pref;
long long int dp[3001][3001],n=0;
long long int solve(long long int i,long long int j){
  	if(i==j){return dp[i][j] = arr[i];}
  	else if(dp[i][j]!=-1){return dp[i][j];}
  	else{
        return dp[i][j] = max(arr[i]-solve(i+1,j),arr[j] - solve(i,j-1));
      }
    
 //return dp[k] = ans;
}
int main(){
	long long int i=0,z=0,j=0,k=0,max=0,count1=0,count2=0;
  	string out;
  	cin >> n;
  	for(i=0;i<n;i++){
    	cin >> z;
      	arr.push_back(z);
    }
  	memset(dp,-1,sizeof(dp));
  	cout << solve(0,n-1)<<endl;
}