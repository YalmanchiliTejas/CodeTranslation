#define LL long long
#include<iostream>
using namespace std;

int main(){
	LL a,b,c;
	cin>>a>>b>>c;
	a =b*10+c;
	if(a%4==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}