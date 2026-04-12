#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#define MAXN 1002

using namespace std;

int main()
{

    int A,B,C,X,Y;
    scanf("%d%d%d%d%d",&A,&B,&C,&X,&Y);
    int sum=0;
    if(X>Y){
        if((A+B)>=2*C){
            sum+=2*C*Y;
            X=X-Y;
        }else{
            sum+=(A+B)*Y;
            X=X-Y;
        }
        if(A>=2*C){
            sum+=2*C*X;
        }else
            sum+=A*X;
    }else{
        if((A+B)>=2*C){
            sum+=2*C*X;
            Y=Y-X;
        }else{
            sum+=(A+B)*X;
            Y=Y-X;
        }
        if(B>=2*C){
            sum+=2*C*Y;
        }else
            sum+=B*Y;
    }
    printf("%d\n",sum);
    return 0;
}
