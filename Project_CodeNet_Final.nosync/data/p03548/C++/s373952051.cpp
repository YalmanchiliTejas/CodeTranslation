#include <iostream>
using namespace std;
int main(void){
    int X,Y,Z;
    cin>>X>>Y>>Z;
    int ans=0;
    ans=(X-Z)/(Y+Z);
    cout<<ans;
    return 0;
}
