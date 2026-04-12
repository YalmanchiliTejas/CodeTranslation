#include<iostream>
#include<algorithm> 
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int main() {
    int a,b,c;
    int x,y;
    cin>>a>>b>>c;
    cin>>x>>y;
    int n=min(x,y);
    int sum=0;
    if(c*2<=a+b) sum+=n*2*c;
    else sum+=n*(a+b);
    if(x-n){
    	n=x-n;
    	if(c*2<a) sum+=n*c*2;
    	else sum+=n*a;
	}
	else{
		n=y-n;
		if(c*2<b) sum+=n*c*2;
		else sum+=n*b;
	}
	cout<<sum;
	
	return 0;
}