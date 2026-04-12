#include<iostream>
using namespace std;
int main(){
int r,g,b;
cin>>r>>g>>b;
b+=g*10;
b+=r*100;
if(b%4==0){
cout<<"YES"<<endl;
}
else{
cout<<"NO"<<endl;
}
return 0;
}