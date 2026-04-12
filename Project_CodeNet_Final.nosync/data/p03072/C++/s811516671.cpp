#include<iostream>
using namespace std;
int main(){
	int n=0,a=0,m=0;
	cin>>n;
	int H[n];
	for(int i=0;i<n;i++){
		cin>>H[i];
	}
	for(int i=0;i<n;i++){
		if(H[i]>a){
			m++;
			a=H[i];
		}else if(H[i]==a){
			m++;
		}
	}
	cout<<m<<endl;
	return 0;
}