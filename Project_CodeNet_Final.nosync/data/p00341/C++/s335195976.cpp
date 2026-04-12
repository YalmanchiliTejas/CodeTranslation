#include<bits/stdc++.h>
using namespace std;

int main(){
  int e[20][2] = {}, a, b = 0;

  for(int i = 0; i < 12; i++){
    cin>>a;
    
    for(int j = 0; j < 12; j++){
      if(e[j][0] == 0){
	e[j][0] = a;
	e[j][1]++;
	break;
      } else if (e[j][0] == a){
	  e[j][1]++;
	  break;
	}
    }
  }

  for(int j = 0; j < 12; j++){
    if(e[j][1]%4 == 0){
      b += e[j][1]/4;
    }
  }

  if(b == 3) cout<<"yes"<<endl;
  else cout<<"no"<<endl;
  return 0;
}

