#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
    long long a,b;a=b=0;
    long long ans=0;
    if(A+B>=2*C){
        if(X>=Y){
            ans+=Y*2*C+(X-Y)*min(2*C,A);    
        }
        else{
            ans+=X*2*C+(Y-X)*min(2*C,B);
        }
    }
    else{
        ans+=X*A+Y*B;
    }
    cout<<ans<<endl;
    return 0;
}