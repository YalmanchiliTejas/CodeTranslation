#include <bits/stdc++.h>
using namespace std;
long long ans, A,B,C,X,Y;
int main(){
    cin>>A>>B>>C>>X>>Y;
    ans=X*A+Y*B;
    if(Y>X){
        ans=min(ans,(Y-X)*B+C*X*2);
        ans=min(ans,Y*C*2);
    }
    else{
        ans=min(ans,(X-Y)*A+C*Y*2);
        ans=min(ans,X*C*2);
    }
    cout<<ans<<'\n';
    return 0;
}
