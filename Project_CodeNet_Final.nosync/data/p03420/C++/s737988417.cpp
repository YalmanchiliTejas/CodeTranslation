#include<iostream>
using namespace std;
int main(){
    long long n,k;cin>>n>>k;
    long long ans=0;
    for(long long i=1;i<=n;i++){
        if(i>k){
            long long x,rest;
            x=n/i;
            rest=n%i;
            ans+=x*(i-k);
            if(rest-k+1>0&&rest>0)ans+=rest-k+1;
        }
    }
    if(k==0)ans=n*n;
    cout<<ans<<endl;
    return 0;
}