#include<bits/stdc++.h>
using namespace std;

int main(){


	int a,b,c,x,y,sum;
	cin>>a>>b>>c>>x>>y;

	if(a+b>2*c){
	
		sum = 2*c*min(x,y);


		if(x-min(x,y)!=0){
			if(2*c<a){
				sum = sum +2*c*(x-y); 
			}else{
				sum = sum + a*(x-y);
			}
		}
		
	
		if(y-min(x,y)!=0){
			if(2*c<b){
				sum = sum +2*c*(y-x); 
			}else{
				sum = sum + b*(y-x);
			}
	
		}
	
	}else{
		sum= a*x+b*y;
	}

	cout<<sum<<endl;

}




