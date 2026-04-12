#include <iostream>
#include <cstdio>
using namespace std;

int main()
{    int A,B,C;
    long int X,Y;
    cin>>A>>B>>C>>X>>Y;
    long int sum=0;
    int index=2*C;
    if(A+B <= index)
        sum=A*X+B*Y;
    else {
        if(X<Y){
            if(index <= B)
                sum=index*Y;
        else    sum=index*X+B*(Y-X);
            }
        else{
            if(index <= A)
                sum=index*X;
            else    sum=index*Y+A*(X-Y);
        }
    }
    cout<<sum<<endl;

    return 0;
}