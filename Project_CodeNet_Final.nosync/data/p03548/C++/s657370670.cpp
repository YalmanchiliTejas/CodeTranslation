#include <iostream>
using namespace std;
int main() {
    int x,y,z;
    int num=0;
    cin>>x>>y>>z;
    int held=z;
    while(held<=x){
        held+=(y+z);
        num+=1;
    }
    if(held>x)num-=1;
    cout<<num<<endl;
}