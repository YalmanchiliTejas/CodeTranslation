#include<bits/stdc++.h>
#define ll long long int
#define IOS cin.tie(NULL);cout.tie(NULL)
#define F first
#define S second
#define pb push_back
//odd day , even month
using namespace std;
ll ans[3001][3001];
ll fun(ll n,ll i, ll j,ll arr[]){
	if(n==1){
		return arr[i];
	}
	if(ans[i][j]!=0){
		return ans[i][j]-1;
	}
	else if(j-i==1){
		ans[i][j]=abs(arr[i]-arr[j])+1;
		return ans[i][j]-1;
	}else {
		ans[i][j]=max(arr[i]-fun(n,i+1,j,arr),arr[j]-fun(n,i,j-1,arr))+1;
		return ans[i][j]-1;
	}
}
int main() {
	IOS;
	ll n,a=0,b=0,c=0,x;
	cin>>n;
	ll arr[n+1];
	for(int i=1; i<=n; i++) {
		cin>>arr[i];
	}
	cout<<fun(n,1,n,arr);

}			