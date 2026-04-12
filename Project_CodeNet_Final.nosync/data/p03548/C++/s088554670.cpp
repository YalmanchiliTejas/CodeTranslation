#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,y,z,ans=0,s=0;
    cin>>x>>y>>z;
    x-=z;
    s=y+z;
    ans=x/s;
    cout<<ans<<endl;
    return 0;
}
