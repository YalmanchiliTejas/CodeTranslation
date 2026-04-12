#include <iostream>
using namespace std;
int main(){
  int n,q,idx=0,a,b;
  cin>>n>>q;
  while(q--){
    cin>>a>>b;
    if(a==1)idx=(idx+b)%n;
    else cout<<((idx+b-1)%n)+1<<endl;
  }
}
