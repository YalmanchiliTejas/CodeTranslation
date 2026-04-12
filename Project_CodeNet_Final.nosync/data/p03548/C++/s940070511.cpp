#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int main(){

    int x,y,z;
    cin>>x>>y>>z;
    int res=0;
    int start=z;
    while ((x-start)>=(z+y)){
        ++res;
        start+=(z+y);
    }


    cout<<res<<endl;
    return 0;
}