#include<iostream>
#include<string>
using namespace std;
string a[10];
int p[10];
int main(){
	int n,b,z,c;
	bool first=true;
	while(true){
	cin>>n;
	if(n==0)break;
	if(!first)cout<<endl;
	first=false;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b>>z>>c;
		p[i]=b*3+c*1;
	}
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(p[j]>p[j-1]){
				string tmps=a[j];
				a[j]=a[j-1];
				a[j-1]=tmps;
				int tmp=p[j];
				p[j]=p[j-1];
				p[j-1]=tmp;
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<","<<p[i]<<endl;
	}
	return 0;
}