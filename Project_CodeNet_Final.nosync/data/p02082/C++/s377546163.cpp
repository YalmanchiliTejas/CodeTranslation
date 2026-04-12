#include <bits/stdc++.h>
using namespace std;

int main(){
    int s,t,p,q,m,y;
    cin>>s>>t>>p>>q>>m>>y;
    int ans=(s^y)^t;
    cout<<ans<<endl;
    return 0;
}
