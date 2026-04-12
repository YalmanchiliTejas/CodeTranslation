#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
 
#define rep(i,n) for(int i=0;i<(n);++i)


int main(){

    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    ll sum=0;
    int price_d;
    if(X>=Y){
            price_d=min((A+B),2*C);
            sum+=price_d*Y;
            sum+=(X-Y)*min(A,2*C);

    }else{
        price_d=min((A+B),2*C);
            sum+=price_d*X;
            sum+=(Y-X)*min(B,2*C);

    }
    cout<<sum<<endl;
}