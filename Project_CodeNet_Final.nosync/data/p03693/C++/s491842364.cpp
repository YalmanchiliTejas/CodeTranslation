#include<iostream>
using namespace std;
int main(){
int r,g,b;
cin>>r>>g>>b;
if(g%2==0&&b%4==0){
cout<<"YES"<<endl;
}
else if(g%2==1&&b%4==2){
cout<<"YES"<<endl;
}
else {
cout<<"NO"<<endl;
}


}