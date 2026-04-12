#include <bits/stdc++.h>
using namespace std;
int main(void){
    int A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;C*=2;
    int ans;
    if(X>=Y){
        ans=X*C;
        ans=min(ans,C*Y+(X-Y)*A);
        ans=min(ans,A*X+B*Y);
    }
    else{
        ans=Y*C;
        ans=min(ans,C*X+(Y-X)*B);
        ans=min(ans,A*X+B*Y);
    }
    cout<<ans<<endl;
}
