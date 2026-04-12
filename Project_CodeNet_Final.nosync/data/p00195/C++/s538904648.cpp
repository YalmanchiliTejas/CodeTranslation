#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int i;
  int z,g,m,b;
  for(;;){
    cin>>z>>g;
    if(z+g==0)
      break;
    m=z+g;
    b=0;
    for(i=1;i<5;i++){
      cin>>z>>g;
      if(z+g>m){
	m=z+g;
	b=i;
      }
    }
    cout<<(char)('A'+b)<<" "<<m<<endl;
  }
  return 0;
}