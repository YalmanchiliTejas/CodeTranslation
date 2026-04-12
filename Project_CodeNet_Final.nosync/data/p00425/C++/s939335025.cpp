#include <iostream>
#include <string>
using namespace std;
int main(){
string a;
int n;
int b;//上面
int c;//前面
int d;//右面
int e;
int f;
int g;
while(cin>>n){
if(n!=0){
b=1;
c=2;
d=3;
e=0;
g=1;
while(e<n){
cin>>a;
if(a=="North"){f=c; c=7-b; b=f;}
if(a=="East"){f=b; b=7-d; d=f;}
if(a=="West"){f=d; d=7-b; b=f;}
if(a=="South"){f=b; b=7-c; c=f;}
if(a=="Right"){f=d; d=7-c; c=f;}
if(a=="Left"){f=c; c=7-d; d=f;}
g=g+b;
e=e+1;}
cout << g<<endl;
}
}
}