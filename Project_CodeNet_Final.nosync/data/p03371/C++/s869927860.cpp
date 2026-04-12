#include <iostream>
using namespace std;
int main(void){
    long long A,B,C,X,Y,sum=0;
    cin>>A>>B>>C>>X>>Y;
    if(C*2<A+B){
        if(X>Y){
            sum+=C*2*Y;
            X-=Y;Y=0;
        }else{
            sum+=C*2*X;
            Y-=X;X=0;
        }
    }
    if(X>0){
        sum+=min(A,C*2)*X;
    }
    if(Y>0){
        sum+=min(B,C*2)*Y;
    }
    cout<<sum<<endl;
}
