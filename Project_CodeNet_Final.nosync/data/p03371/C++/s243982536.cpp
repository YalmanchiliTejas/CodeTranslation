#include<bits/stdc++.h>

using namespace std;

int main(){
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;

    int sum=0;
    int half = C*2;
    int ab = A+B;
    if(half<ab)
        if(X>Y){
            sum+= half * Y;
            if(A>half)
                sum+=half*(X-Y);
            else
                sum+=A*(X-Y);
        }else{
            sum+=half * X;
            if(B>half)
                sum+=half*(Y-X);
            else
                sum+=B*(Y-X);
        }

    else
        sum+=A*X+B*Y;


    cout<<sum;
}
