#include <iostream>
using namespace std;

int main() {
  int n, k, l;
  cin>>n>>k>>l;
  if ((10*k+l)%4==0){
    cout<<"YES"<<endl;
  }
  else {
    cout<<"NO"<<endl;
  }
  return 0;
}