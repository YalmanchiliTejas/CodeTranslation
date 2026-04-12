#include<iostream>
#include<string>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if((b*10+c)%4==0){
		cout<<"YES"<<endl;
	}
	
	else if((b*10+c)%4!=0){
	 cout<<"NO"<<endl;
}
}