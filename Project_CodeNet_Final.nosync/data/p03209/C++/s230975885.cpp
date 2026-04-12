#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int N=0;
long X=0;
long ans=0;
long l(int n) {return pow(2,n+2)-3;}
long p(int n) {return pow(2,n+1)-1;}
long b(int n) {return pow(2,n+1)-2;}
int pat[6]={0,0,1,2,3,3};
 
void burger(int n,long x){
  	if(n==1) {
      	ans+=pat[x];
    }
  	else if(x>=l(n)-2 ){
    	ans+=p(n);
    }
	else if(x > l(n-1)+3) {
      	ans+=p(n-1)+1;
     	burger(n-1,x-l(n-1)-2);
    }
  	else if(l(n-1)+2==x || x==l(n-1)+3){
    	ans+=p(n-1)+1;
    }
  	else if (x>1){
    	burger(n-1,x-1);
    }
}

int main(){
  	cin >>N >>X;
	
  	burger(N,X);
  
  	cout <<ans <<endl;
  
}