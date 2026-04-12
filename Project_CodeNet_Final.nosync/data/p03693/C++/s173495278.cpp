#include <iostream>
using namespace std;

int main() {
	int r,g,b,x;
	cin>>r>>g>>b;
	x=100*r+10*g+b;
	if(x%4==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
