#include<iostream>
using namespace std;
int main(){
	long long A,B,C,x,y;
	cin>>A>>B>>C>>x>>y;
	if(A+B<=C*2)
		cout<<A*x+B*y;
	else
		if(x>y)
			cout<<min(2*y*C+A*(x-y),2*C*x);
		else
			cout<<min(2*x*C+B*(y-x),2*C*y);
	return 0;
}