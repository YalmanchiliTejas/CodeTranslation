#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,ans=0,mx=0,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x>=mx){
			ans++;
			mx=x;
		}
	}
	cout<<ans<<endl;
	return 0;
}
