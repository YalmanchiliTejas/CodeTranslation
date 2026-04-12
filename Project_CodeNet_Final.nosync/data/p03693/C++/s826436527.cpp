#include <iostream>
using namespace std;
int main(){
    int r=0,g=0,b=0,sum=0,judge=0;
    cin>>r;
    cin>>g;
    cin>>b;
    r=r*100;
    g=g*10;
    sum=r+g+b;
    judge=sum%4;
    if(judge==0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    cout<<endl;
}
