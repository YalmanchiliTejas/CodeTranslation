#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define ll long long
using namespace std;

int main(){
    long long A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    long long ans=1e9+1;

    for (int Z=0;Z<=2*max(X,Y);Z+=2){
        ans=min(ans,A*(max(0ll,X-Z/2))+B*(max(0ll,Y-Z/2))+Z*C);
    }

    cout<<ans<<endl;

    return 0;
}