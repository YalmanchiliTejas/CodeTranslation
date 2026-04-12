#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int a[12],r=0;
  for(int i=0;i<12;i++) cin>>a[i];
  sort(a,a+12);
  for(int i=0;i<3;i++) for(int j=1;j<4;j++) if(!(a[i*4]==a[i*4+j])) r++;
  cout<<(r?"no":"yes")<<endl;
  return 0;
}