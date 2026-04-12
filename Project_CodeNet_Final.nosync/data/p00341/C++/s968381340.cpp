#include<bits/stdc++.h>
using namespace std;

#define NUM 12

int main(){
  int x[NUM];

  for(int i=0;i<NUM;++i){
    cin >> x[i];
  }
  
  sort(x,x+NUM);

  for(int i = 0; i<3 ;++i){
    for(int k=i*4;k<i*4 + 4 - 1;++k){
      if(x[k] != x[k+1]){
	cout << "no" << endl;
	return 0;
      }
    }
  }

  cout << "yes" << endl;
  
  return 0;
}

