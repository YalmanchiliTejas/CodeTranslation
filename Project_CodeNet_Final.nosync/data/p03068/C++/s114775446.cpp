#include <iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n;
	char p[100];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	cin>>k;
	for(int i=0;i<n;i++){
		if(p[k-1]!=p[i]){
			cout<<"*";
		}else{
			cout<<p[i];
		}
	}
	return 0;
} 