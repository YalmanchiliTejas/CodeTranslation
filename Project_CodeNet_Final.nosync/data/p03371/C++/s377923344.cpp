#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int A,B,C,X,Y,minn;
    int total=0;
    while(cin>>A>>B>>C>>X>>Y)
    {
       int sum1=0,sum2=0;
       total=X*A+Y*B;
       if(X>Y)
         {
             sum1=Y*C*2+A*(X-Y);
             sum2=X*C*2;
         }
        else
        {
            sum1=X*C*2+B*(Y-X);
            sum2=Y*C*2;
        }
        minn=min(sum1,sum2);
        cout<<min(minn,total)<<endl;
    }
    return 0;
}

