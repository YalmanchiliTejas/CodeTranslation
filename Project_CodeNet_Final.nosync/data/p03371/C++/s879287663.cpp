#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#define ll long long
using namespace std;


int main(){
    int A,B,C;cin>>A>>B>>C;
    int X,Y;cin>>X>>Y;
    ll cost=0;
    int m=min(X,Y);
    // m マイメまでは安い方をとり続ける

    if(A+B >= 2*C){
        cost += 2*C*m;
    } else {
        cost += A*m + B*m;
    }

    X = X-m; Y=Y-m;
    if(X>0){
        if(A>2*C){
            cost += 2*C*X;
        } else {
            cost += A*X;
        }
    }

    if(Y>0){
        if(B>2*C){
            cost += 2*C*Y;
        } else {
            cost += B*Y;
        }
    }

    cout<<cost<<endl;


    return 0;
}

 

