#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,maxn=0,ans=0,temp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		if(temp>=maxn){
			maxn=temp;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}