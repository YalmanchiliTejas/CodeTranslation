#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(){

    int x,y,z;

    cin>>x>>y>>z;

    int ans=x/(y+z);
    
    if (x%(y+z)>=z)
        cout<<ans<<endl;
    else
        cout<<ans-1<<endl;

}
