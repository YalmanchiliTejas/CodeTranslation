#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr(n+1,0);
	for(int i=1; i<=n; i++) cin>>arr[i];
	vector<int>temp(arr.begin(),arr.end());
	sort(arr.begin(),arr.end());
	int mid = n/2;
	for(int i=1; i<=n; i++){
		if(temp[i]<=arr[mid]) cout<<arr[mid+1]<<'\n';
		else cout<<arr[mid]<<'\n';
	}
}