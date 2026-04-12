#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define int long long

bool comp(int a,int b){
return a>b ;	
}


bool foo(int arr[],int n,int k){
	
	if(n==0 || k==0)
	return 0;
	
	for(int i=0;i<n;i++){
		if(k>=arr[i]){	
			bool state=foo(arr,n,k-arr[i]);
			if(!state)
				return 1;
		}
	}
	return 0;
}

signed main(){

//int mod=1000000007;

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#else
// online submission
#endif

int n ;
cin >> n  ;

int arr[n];
int sum=0;
for(int i=0;i<n;i++){
cin >> arr[i] ;
sum+=arr[i];
}


int dp[n]={0};

for(int i=n-1;i>=0;i--){
	for(int j=i;j<n;j++){
		
		if(i==j){
			dp[j]=arr[j] ;
		}
		else{
			dp[j]=max(arr[i]-dp[j],arr[j]-dp[j-1]);
		}
	}
}



cout<<dp[n-1] ;
	return 0;
    
}


