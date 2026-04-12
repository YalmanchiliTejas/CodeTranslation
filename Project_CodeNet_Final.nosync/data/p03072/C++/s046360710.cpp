#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n]; int minn[n];
	
	for(int i=0;i<n;i++)
	{
	cin>>arr[i];    
	}
	minn[0]=arr[0];
	int ans=1;
	for(int i=1;i<n;i++)
	{
	    if(arr[i]>=minn[i-1]){ ans++; minn[i]=arr[i];}
	    else minn[i]=minn[i-1];
	}
	cout<<ans<<endl;
	
	return 0;
}
