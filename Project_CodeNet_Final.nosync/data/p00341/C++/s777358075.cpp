#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[12],i,j;bool f=true;
  for(i=0;i<12;i++)cin>>a[i];sort(a,a+12);
  for(i=0;i<3;i++)for(j=0;j<3;j++) f&=(a[i*4+j]==a[i*4+j+1]);
  cout<<(f?"yes":"no")<<endl;
  return 0;
}