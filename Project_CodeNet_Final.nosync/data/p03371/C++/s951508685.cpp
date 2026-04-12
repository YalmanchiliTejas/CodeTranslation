#include <iostream>
using namespace std;
int main(void){
    long A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    long ans=100000000000000000;;
    for(int D=0;D<=max(X,Y);D++){
        ans=min(ans,C*2*D+A*max((long)0,X-D)+B*max((long)0,Y-D));
    }
    cout<<ans<<endl;
}