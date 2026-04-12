#include <bits/stdc++.h>
using namespace std;
int x,y,z,t,ans;
int main(){
    cin>>x>>y>>z;
    t=z;
    while(t+y+z<=x){
        t+=y+z;
        ans++;
    }
    cout<<ans;
    return 0;
}