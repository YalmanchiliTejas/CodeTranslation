#include<iostream>
using namespace std;
int main(){
	int X,Y,Z,l,i=0;
	cin>>X>>Y>>Z;
	l=X-Z;
	for(;;){
		l=l-(Y+Z);
		if(l<0)break;
		i++;
	}
	cout<<i;
}