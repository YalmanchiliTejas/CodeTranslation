#include <bits/stdc++.h>
using namespace std;
int main() {
    int X,Y,Z; cin>>X>>Y>>Z;
    int ans=0;
    for(int i=0;i<=(X-Z)/(Y+Z);i++){
        ans=i;
    }
    cout<<ans;
    return 0;
}