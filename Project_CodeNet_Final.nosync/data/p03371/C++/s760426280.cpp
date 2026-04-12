#include <iostream>
using namespace std;
int A,B,C,X,Y;
int main() {
	cin>>A>>B>>C>>X>>Y;
	int sum=0;
	int minm=min(X,Y);
	if(2*C>A+B){
		sum+=minm*(A+B);
	}
	else
		sum+=minm*2*C;
	if(minm==X){
		int d=Y-X;
		if(C*2>B)
		sum+=d*B;
		else
		sum+=d*2*C;
	}
	else if(minm==Y){
		int d=X-Y;
		if(C*2>A)
		sum+=d*A;
		else
		sum+=d*2*C;
	}
	cout<<sum<<endl;
	return 0;
}