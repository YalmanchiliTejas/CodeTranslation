#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b;
    1<=r,g,b<=9;
    cin>>r>>g>>b;
    int a=r*100+g*10+b;
    if(a%4==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}