#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int b,n;
	cin>>n;
	char a[20];
	cin>>a;
	cin>>b;
	for(int i=0;i<n;i++){
		if(a[i]!=a[b-1]){
			cout<<"*";
		}else cout<<a[i];
	}cout<<endl;
	
}