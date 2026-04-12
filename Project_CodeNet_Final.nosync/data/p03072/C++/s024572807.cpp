#include <iostream>
using namespace std;

int main(){
  int n,i,j,c=0;
  bool b=0;
  cin>>n;
  int h[n];
  for (i=0;i<n;i++)cin>>h[i];
  for (i=0;i<n;i++){
    b=1;
    for (j=0;j<i;j++)b&=(h[j]<=h[i]);
    c+=b;
  }
  cout<<c<<endl;
}
