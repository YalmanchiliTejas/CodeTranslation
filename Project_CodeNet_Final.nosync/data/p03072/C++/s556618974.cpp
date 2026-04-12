#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	int cnt=1;
	int maxi=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>=maxi)
		{cnt++;
		maxi=arr[i];
			
		}
		
	}
	cout<<cnt;
	return 0;
}