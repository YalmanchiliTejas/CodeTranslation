#include<iostream>
using namespace std;

int main() {
    long N, K;
    cin>>N>>K;
    long ans = 0;
    for(long b=K+1;b<=N;++b){
        ans += N/b*(b-K);
        if((N%b)-(K-1) > 0) ans += (N%b) - (K-1);
    }
    if(K==0)ans -= N-K;
    cout<<ans<<endl;
}
