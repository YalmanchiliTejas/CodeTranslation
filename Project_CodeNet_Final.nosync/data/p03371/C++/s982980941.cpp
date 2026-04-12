#include<iostream>
#include<string>
using namespace std;
int main(){
	long long a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	if ((a+b)>2*c){
		if (x>y){
			long long d=2*c*y;
			long long e=a*(x-y);
			if (a>2*c)
			cout<<2*c*x<<endl;
			else cout<<d+e<<endl;
		}
		else {
			long long d=2*c*x;
			long long e=b*(y-x);
			if (b>2*c)
			cout<<2*c*y<<endl;
			else cout<<d+e<<endl;
		}
	}
	else
	cout<<a*x+b*y<<endl;
	return 0;
}