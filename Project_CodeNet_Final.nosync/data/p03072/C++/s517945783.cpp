#include<iostream>
using namespace std;

int main(){
	int n,ans=0;
	bool bisa=true;
	cin>>n;
	int arr[n+4];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		bisa=true;
		for(int j=i;j>=1;j--){
			if(arr[i]<arr[j]){
				bisa=false;
			}	
		}
		if(bisa==true){
			ans++;
		
		
	}
}
cout<<ans<<endl;
}