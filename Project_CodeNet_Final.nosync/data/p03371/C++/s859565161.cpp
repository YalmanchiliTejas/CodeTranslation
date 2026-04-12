#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
using namespace std;

int main(){
    int A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
    long long ans;
    if(A+B<=2*C)ans=X*A+Y*B;
    else{
        int M,m,D;
        if(X>=Y){
            M=X-Y,m=Y;
            D=A;
        }
        else{
            M=Y-X,m=X;
            D=B;
        }
        ans=2*m*C;

        if(D>=2*C) ans+=2*C*M;
        else ans+=D*M;
    }
    cout<<ans<<endl;
    return 0;
}