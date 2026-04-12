#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    int X,Y,Z,ans=0;
    cin>>X>>Y>>Z;
    X-=Z;
    for(;;){
        if(X-Y-Z<0){
            cout<<ans<<endl;
            return 0;
        } else {
            ans++;
            X-=Y+Z;
        }
    }
}