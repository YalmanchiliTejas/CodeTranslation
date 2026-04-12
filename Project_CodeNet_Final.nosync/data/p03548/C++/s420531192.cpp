#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y,z,ans=0;cin>>x>>y>>z;
    x-=z;
    while(x>=y+z){
        x-=y+z;
        ans++;
    }
    cout<<ans<<endl;
}