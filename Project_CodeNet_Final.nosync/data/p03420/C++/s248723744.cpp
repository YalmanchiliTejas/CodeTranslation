#include<iostream>
using namespace std;

main(){
    int long long N,K;
    cin>>N;
    cin>>K;
    int long long b=0;
    int long long ans=0;
    for(b=(K+1);b<=N;b++){
        ans+=(N/b)*(b-K);
        if(N%b>=K&&K!=0) ans+=((N%b)-K+1);
        else if(K==0) ans+=(N%b);
    }
    cout<<ans;
}