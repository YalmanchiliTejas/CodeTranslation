#include <iostream>

using namespace std;
int main(){
	int a,b,c,t;
	cin>>a>>b>>c;
	t=100*a+10*b+c;
	if(t%4==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}
