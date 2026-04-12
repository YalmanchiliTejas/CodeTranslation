#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<=n;i++)
using namespace std;
int main(){
    long long A,B,C,X,Y,price=__LONG_LONG_MAX__;
    cin>>A>>B>>C>>X>>Y;
    REP(i,100000){
        long long tmp = i*(2*C)+max((long long)0,(X-i))*A+max((long long)0,(Y-i))*B;
        price = min(price,tmp);
    }
    cout<<price<<endl;
}