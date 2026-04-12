#include<iostream>
using namespace std;

int main(){
    int r,g,b;
    cin>>r>>g>>b;

    int total=100*r+g*10+b;
    bool can=false;
    if(total%4==0)can=true;
    if(can)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
