#include<bits/stdc++.h>
using namespace std;


int main(){
  
  int n, c = 0 ,res ;
  
  scanf("%d",&n);
  if(n >= 15)
  {
  		c = n/15;
  		res = (n * 800) - (c * 200);
	}else
	{
	res = n * 800;
	}  	
printf("%d", res);
  
  
 return 0 ; 
  }
