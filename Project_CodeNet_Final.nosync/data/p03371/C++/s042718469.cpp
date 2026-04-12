#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll= long long;
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    int ans=0;
    if(A+B>2*C){
        ans+=min(X,Y)*2*C;
        if(min(X,Y)==X&&B<2*C){
            ans+=(Y-min(X,Y))*B;
        }
        else if(min(X,Y)==Y&&A<2*C){
            ans+=(X-min(X,Y))*A;
        }
        else{
            ans+=(max(X,Y)-min(X,Y))*2*C;
        }
    }
    else{
        ans=A*X+B*Y;
    }
    cout<<ans<<endl;
    
  
 }
 


