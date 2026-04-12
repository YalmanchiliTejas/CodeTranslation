#include<bits/stdc++.h>
using namespace std;
vector<vector<long long int> > ve;
long long int recurse(long long int *arr,int i,int j){
	if(i>j){
		return 0;
	}
	else if(i==j){
		ve[i][j]=arr[i];
		//cout<<i<<" "<<j<<" "<<ve[i][j]<<endl;
		return arr[i];
	}
	else if((i+1)==j){
		long long int maximum=max(arr[i],arr[j]);
		ve[i][j]=maximum;
		return maximum;
	}
	else if(ve[i][j]!=0){
		return ve[i][j];
	}
	else{
		long long int max1=recurse(arr,i+1,j-1)+arr[i];
		long long int max2=recurse(arr,i+2,j)+arr[i];
		long long int max3=recurse(arr,i+1,j-1)+arr[j];
		long long int max4=recurse(arr,i,j-2)+arr[j];
		ve[i][j]=min(max1,max2);
		long long int fake=min(max3,max4);
		ve[i][j]=max(ve[i][j],fake);
		return ve[i][j];
	}
}
int main(void){
	int n;
	cin>>n;
	ve.resize(n);
	for(int i=0;i<n;i++){
		ve[i].resize(n);
	}
	long long int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	long long int ans=recurse(arr,0,n-1);
	long long int sum=0;
	for(int i=0;i<n;i++)
	sum+=arr[i];
	long long int fake=sum-ans;
	cout<<(ans-fake)<<endl;
}