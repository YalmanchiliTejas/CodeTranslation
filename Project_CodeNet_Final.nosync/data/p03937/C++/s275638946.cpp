#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void){
  int i,j,k,t,tmp;
  string s;
  int a,b;
  int H,W;
  char c;
  cin>>H>>W;
  t=0;
  for(i=1;i<=H;i++){
    for(j=1;j<=W;j++){
      cin>>c;
      if(c=='#') t++;
    }
  }
  if(t==W+H-1) cout<<"Possible";
  else cout<<"Impossible";
  cout<<endl;

  return 0;
}