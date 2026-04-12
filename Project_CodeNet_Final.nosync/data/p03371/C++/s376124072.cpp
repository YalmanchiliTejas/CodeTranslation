#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int A,B,C,X,Y;  cin>>A>>B>>C>>X>>Y;
    int maisu=X+Y;
    int ans=0;
    if(2*C<A+B){
        ans=2*C*min(X,Y);
    }
    else{
        ans=(A+B)*min(X,Y);
    }
    if(X-Y>0){//Xのが大きい
        ans+=min(A,2*C)*(X-Y);
    }
    else {
        ans+=min(B,2*C)*(Y-X);
    }
    cout<<ans;
    return 0;
}