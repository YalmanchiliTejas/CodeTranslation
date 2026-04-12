#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	long long int a,b,c,x,y,ans=0;
	cin>>a>>b>>c>>x>>y;
	if(a+b<2*c){
		cout<<a*x+b*y<<endl;
	}
	else if(x>y){
		if(a<2*c){
			cout<<a*(x-y)+2*c*y<<endl;
		}
		else{
			cout<<2*c*x<<endl;
		}
	}
	else{
		if(b<2*c){
			cout<<b*(y-x)+2*c*x<<endl;
		}
		else{
			cout<<2*c*y<<endl;
		}
	}
	return 0;
	
}