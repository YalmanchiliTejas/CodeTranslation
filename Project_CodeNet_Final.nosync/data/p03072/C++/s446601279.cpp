#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define   ull unsigned long long 
const int MAX=1e6+9;
const int mod=1e9+7;
using namespace std;
int cnt[MAX];

int main(){
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int mx=arr[1];
	int cnt=1;
	for(int i=2;i<=n;i++){
		if(arr[i]>=mx){
			cnt++;
			mx=arr[i];
		}
	}
	cout<<cnt;	

}