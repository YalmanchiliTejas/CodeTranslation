#include<iostream>
using namespace std;
using ll=long long;
#define MOD 1000000007;

int main(){
    ll N;
    ll A[200002];
    cin>>N;
    ll sum=0;
    ll res=0;
    for(ll i=1;i<=N;i++){
        cin>>A[i];
        sum+=A[i];
        sum%=MOD;
    }
    for(ll i=1;i<N;i++){
        sum-=A[i];
        if(sum<0){
            sum+=MOD;
        }
        res+=(A[i]*sum)%MOD;
        res%=MOD;
    }
    cout<<res<<endl;
    return 0;
}