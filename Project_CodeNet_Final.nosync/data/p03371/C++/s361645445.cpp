#include<iostream>
#include<set>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i < (int)(n); i++)

#include <algorithm>
using namespace std;
#include <cmath>
#include <string>
#include<vector>
#define elif else if
typedef long long ll;
#define TENNINE 1000000005
#define TENFIVE 200005
int N;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    ll X,Y;
    cin>>X>>Y;
    ll sum =0;
    if(A+B<=2*C) sum = A*X+ B*Y;
    else{
        sum = min(X,Y)*2*C;
        ll tmp = min(X,Y);
        X -=  tmp;
        Y -= tmp;
        
        if(2*C < A )
            sum +=  X*2*C;
        else
        {
            sum+= A*X;
        }
            
        if(2*C < B )
            sum +=  Y*2*C;
        else
        {
            sum+=B*Y;
        }
        
    } 
    cout<<sum;
    return  0;
}