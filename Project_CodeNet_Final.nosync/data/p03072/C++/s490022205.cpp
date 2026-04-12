#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[50],ans=0,max=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(max<=a[i]){
			ans++;
			max=a[i];
		}
	}
	cout<<ans<<endl;
  return(0);
}