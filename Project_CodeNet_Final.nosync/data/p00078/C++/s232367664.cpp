#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#define Sq(x,y) (s[x+(y)*n])
using namespace std;

int main() {
	int n;
	int *s;
	int x,y;
	
	while(cin>>n,n){
		
		s=new int[n*n];
		for(int i=0;i<n*n;++i)s[i]=0;
		
		x=n/2,y=n/2+1;
		Sq(x,y) = 1;
		
		for(int i=2;i<=n*n;++i){
			++x;++y;
			while(true){
				if(x>=n)x=0;
				else if(x<0)x=n-1;
				if(y>=n)y=0;
				
				if(Sq(x,y)==0){Sq(x,y)=i;break;}
				else --x,++y;
			}
		}
		
		for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			printf("%4d",Sq(j,i));
		puts("");
		}
		
		delete[]s;
	}
	return 0;
}