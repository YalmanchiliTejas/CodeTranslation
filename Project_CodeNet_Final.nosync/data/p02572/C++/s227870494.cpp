#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;
using ll=long long;


int main(){
    ll N;
    cin >> N;
    ll mod=1000000007;
    vector<ll> A(N);
    vector<ll> sums(N+1);
    for(ll i=0;i<N;i++){
        cin >> A[i];
        sums[i+1]=(sums[i]+A[i])%mod;
    }
    ll res=0;
    for(ll i=0;i<N-1;i++){
        ll sum;
        if(sums[N]-sums[i+1]<0){
            sum=sums[N]-sums[i+1]+mod;
        }else{
            sum=sums[N]-sums[i+1];
        }
        res+=(A[i]*sum)%mod;
    }
    cout << res%mod << endl;
}