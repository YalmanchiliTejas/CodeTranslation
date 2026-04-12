#include<iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
	int b[a];
	for(int i=0;i<a;i++){
	cin>>b[i];	
	}
	int c=1,d=b[0];
	for(int i=1;i<a;i++){
		if(b[i]>=b[i-1]&&b[i]>=d){
			c++;
			d=b[i];
		}
	}
	cout<<c<<endl;
	return 0;
}