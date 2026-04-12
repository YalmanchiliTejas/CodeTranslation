#include<iostream>
using namespace std;
int main(){
    int x,y,z,dfd,dfder;
    cin>>x>>y>>z;
    dfd=x-z;
    dfder=z+y;
    cout<<dfd/dfder<<endl;
    return 0;
}