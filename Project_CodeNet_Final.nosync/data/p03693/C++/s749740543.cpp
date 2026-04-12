#include <iostream>
using namespace std;
int r,g,b,sum;
int main() {
	cin>>r>>g>>b;
	sum=100*r+10*g+b;
	if(sum%4==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}