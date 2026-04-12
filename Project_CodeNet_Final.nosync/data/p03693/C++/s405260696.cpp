#include <iostream>
using namespace std;

int main(){
int r,g,b,A;
cin>>r>>g>>b;
A=(r*100+g*10+b);
if(A%4==0)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
