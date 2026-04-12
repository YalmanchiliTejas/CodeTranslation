#include <bits/stdc++.h>
using namespace std; 
  
int main(){
 int N,max=0,cnt=0,hgt=0;
  cin>>N;

  
  for(int i=0;i<N;i++){
    cin>>hgt;
  	if(hgt>=max){
      cnt++;
      max=hgt;
    	}
  }
	cout<<cnt<<endl;
}