#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int A,B,C,X,Y;
    scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);

    int sum=0;
    if(A+B<2*C){
        sum=A*X+B*Y;
    }
    else{
        if(X<=Y){
            sum=2*C*X;
            if(B<2*C){
                sum+=(Y-X)*B;
            }
            else{
                sum+=2*(Y-X)*C;
            }
        }
        else{
            sum=2*C*Y;
            if(A<2*C){
                sum+=(X-Y)*A;
            }
            else{
                sum+=2*(Y-X)*C;
            }
        }
    }

    printf("%d\n",sum);

    return 0;
}