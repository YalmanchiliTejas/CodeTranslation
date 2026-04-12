#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a,b,c,sum=0;
	cin>>a>>b>>c;
	sum=a*100;
	sum+=b*10;
	sum+=c;
	if(sum%4==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}