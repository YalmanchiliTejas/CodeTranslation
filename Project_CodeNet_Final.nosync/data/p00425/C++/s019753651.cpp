#include <iostream>
using namespace std;
int main(){
	int a[3]={1,2,3};
	int n,i,temp,out;
	char b[6];
	while(cin>>n){
		if(n==0){break;}
		a[0]=1,a[1]=2,a[2]=3;
		out=1;
		for(i=0;i<n;i++){
			cin>>b;
			if(b[0]=='N'){
				temp=a[0];
				a[0]=a[1];
				a[1]=7-temp;
				out+=a[0];
			}else if(b[0]=='E'){
				temp=a[2];
				a[2]=a[0];
				a[0]=7-temp;
				out+=a[0];
			}else if(b[0]=='W'){
				temp=a[0];
				a[0]=a[2];
				a[2]=7-temp;
				out+=a[0];
			}else if(b[0]=='S'){
				temp=a[1];
				a[1]=a[0];
				a[0]=7-temp;
				out+=a[0];
			}else if(b[0]=='R'){
				temp=a[1];
				a[1]=a[2];
				a[2]=7-temp;
				out+=a[0];
			}else if(b[0]=='L'){
				temp=a[2];
				a[2]=a[1];
				a[1]=7-temp;
				out+=a[0];
			}
		}
		cout<<out<<endl;
	}
	return 0;
}