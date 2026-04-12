#include <iostream>
#include <algorithm>
using namespace std;
int main(){

  int n,t[300010],r=1;
  cin>>n;
  for(int i=0;i<n;i++) cin>>t[i];
  int le=t[0];
  for(int i=1;i<n;i++){
    le-=10;
    if(le<0) r=0;
    le=max(le,t[i]);
  }

  reverse(t,t+n);

  le=t[0];
  for(int i=1;i<n;i++){
    le-=10;
    if(le<0) r=0;
    le=max(le,t[i]);
  }

  cout<<(r?"yes":"no")<<endl;
  return 0;


}

