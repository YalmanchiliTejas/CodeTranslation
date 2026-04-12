#include <iostream>
using namespace std;
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    int n=0;
    while(x>=y*n+z*(n+1)){
        n++;
    }
    cout<<n-1<<endl;
    return 0;
}