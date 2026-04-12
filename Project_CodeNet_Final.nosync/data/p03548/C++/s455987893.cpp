#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    int x,y,z,cnt=0;
    cin>>x>>y>>z;
    x-=(z*2)+y;
    cnt++;
    while(x-y>0 && x-(y+z)>=0){
        x-=y+z;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
