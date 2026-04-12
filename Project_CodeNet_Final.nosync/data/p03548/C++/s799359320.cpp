#include <iostream>
#include <math.h>
#include <string> 
using namespace std;
#define MAX 200000

int main(){
    int x,y,z,sum;
    cin>>x>>y>>z;
    sum=(x-z)/(y+z);
    cout<<sum<<endl;
    return 0;
}