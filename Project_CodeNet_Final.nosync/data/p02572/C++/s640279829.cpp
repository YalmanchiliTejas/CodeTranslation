// Write your code here
#include <bits/stdc++.h>
using namespace std;
#include <iostream>

int main(){
	long long int n,ans=0,m,tmp=1,x;
	m=1e9+7;
	cin>>n;
	long long int arr[n],prefix[n+1];
	for(int j=0;j<n;j++){
		cin>>x;
		arr[j]=x%m;
	}
	prefix[0]=0;
	for(int j=0;j<n;j++){
		tmp=(prefix[j]+arr[j]);
		prefix[j+1]=(tmp)%m;
	}
	for(int j=0;j<n;j++){
		tmp=prefix[n]-prefix[j+1];
		tmp=tmp%m;
		tmp=arr[j]*tmp;
		tmp=tmp%m;
		ans=ans+tmp;
		ans=ans%m;
        if(ans<0){
            ans=ans+m;
            ans=ans%m;
        }
	}
	
	cout<<ans;
}