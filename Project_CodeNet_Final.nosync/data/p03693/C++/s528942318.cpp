#include<iostream>
using namespace std;
int main(){
int a,b,c,d;
cin>>a>>b>>c;
d=c+b*10+a*100;
if(d%4==0)
    cout<<"YES";
else
    cout<<"NO";
}

