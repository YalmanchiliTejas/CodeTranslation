#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
  	int arr[n];
 	int mx=0;
 	int ans=0;
  	for(int i=0;i<n;i++){
      
      cin>>arr[i];
      if(arr[i]>=mx) ++ans;
      mx=max(mx,arr[i]);
    }
  cout<<ans;
}