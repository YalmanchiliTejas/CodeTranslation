#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int e[12],i,f=1;
  for(i=0;i<12;i++)
    cin>>e[i];
  sort(e,e+12);
  for(i=0;i<12;i+=4)
    if(!(e[i]==e[i+1]&&e[i+1]==e[i+2]&&e[i+2]==e[i+3]))
      f=0;
  if(f)
    cout<<"yes\n";
  else
    cout<<"no\n";
}

