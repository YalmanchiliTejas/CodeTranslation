#include <iostream>
using namespace std;
int main(void){
    int x,y,z,i;
    cin>>x>>y>>z;
    x-=z;
    i=x/(y+z);
    cout<<i<<endl;
    return 0;
}