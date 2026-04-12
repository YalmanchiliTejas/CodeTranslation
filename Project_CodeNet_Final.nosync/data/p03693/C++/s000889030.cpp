#include<iostream>
using namespace std;

int a,b,c,sum;//KはくまでX円でNはくする

int main(){

	cin>>a>>b>>c;
	sum=a*100+b*10+c;
	if(sum%4==0)	cout<< "YES"<<endl;
	else cout<<"NO"<<endl;
		return 0;

	}
