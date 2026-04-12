#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    char a,i,u,e =0;
    cin>>a>>i>>u;
      e = a*100+i*10+u*1 ;
    if(e%4 == 0)cout<<"YES";
    else cout<<"NO";
}
