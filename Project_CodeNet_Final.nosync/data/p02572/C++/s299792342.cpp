#include <bits/stdc++.h>
using namespace std;

int main(){
    long N;cin>>N;
    vector<long> a(N);
    long sum=0;
    for(long i=0;i<N;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<long> asum(N);
    asum[0]=(sum-a[0])%1000000007;
    long vsum=a[0];
    for(long i=1;i<N;i++){
        vsum+=a[i];
        asum[i]=(sum-vsum)%1000000007;
    }
    long res=0;
    for(long i=0;i<N;i++){
        res=(res+(asum[i]*a[i])%1000000007)%1000000007;
    }
    cout<<res<<endl;
}