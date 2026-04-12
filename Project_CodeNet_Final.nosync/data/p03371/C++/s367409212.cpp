#include <bits/stdc++.h>
using namespace std;

int main(void){
  long long int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  if(min(a,b)>=2*c){
  	cout<<max(x,y)*2*c<<endl;
  	return 0;
  }
  if(a+b<=2*c){
  	cout<<a*x+b*y<<endl;
  	return 0;
  }
  if(a+b>2*c){
    if(x<=y){
  	  cout<<min(c*2*x+b*(y-x),2*c*y)<<endl;
  	  return 0;
  	}
  	if(y<=x){
  	  cout<<min(c*2*y+a*(x-y),2*c*x)<<endl;
  	  return 0;
  	}	
  }
}
