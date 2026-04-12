#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    long A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    long sum1=0,sum2=0,sum3=0;
    
    if(X>Y){
        sum1+=2*C*Y+ A*(X-Y);
    }else{
        sum1+=2*C*X+ B*(Y-X);
    }
    sum2+=2*C*max(X,Y);
    sum3+=A*X+B*Y;
    cout<<min(min(sum1,sum2),sum3)<<endl;
    return 0;
}
