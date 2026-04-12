#include<iostream>
#define  ll long long

using namespace std;

int main(){
    ll x,y,z;
    cin>>x>>y>>z;
    x-=z;
    cout<<x/(y+z)<<endl;
    return 0;
}