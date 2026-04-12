#include<bits/stdc++.h>
using namespace std;

int main(){

  int N;


  cin>>N;

  int h[22];
  
  
  for(int i=0;i<N;i++){
	cin>>h[i];
  }

  int cnt=1;
  
  for(int i=1;i<N;i++){

	int maxx=0;
	for(int j=0;j<i;j++){
	  maxx=max(maxx,h[j]);
	}
	if(maxx<=h[i]){
	  cnt++;
	}
  }

  cout<<cnt<<endl;
  
  
  return 0;
}
