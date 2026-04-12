#include <bits/stdc++.h>
using namespace std;
int main(void){
  char a,b,c;
  int i=0;
  scanf("%c%c%c",&a,&b,&c);
  if(a==b && b==c){
    i=1;
  }if(i==1){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
  }
}