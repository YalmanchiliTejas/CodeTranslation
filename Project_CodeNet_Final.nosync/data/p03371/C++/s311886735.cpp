#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;

    int ans=0;
    if(A+B<=2*C){
        ans+=A*X+B*Y;
    }else{
        int minPz,minPz_p,maxPz,maxPz_p;
        if(X>=Y){minPz=Y;minPz_p=B;maxPz=X;maxPz_p=A;}
        else{minPz=X;minPz_p=A;maxPz=Y;maxPz_p=B;}

        if(2*C<=maxPz_p) ans+=2*maxPz*C;
        else ans+=2*minPz*C+(maxPz-minPz)*maxPz_p;
    }

    cout<<ans<<endl;
}