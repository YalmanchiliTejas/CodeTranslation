#include<iostream>
using namespace std;
int main(){
    int N,K;
    long long ans=0;
    cin >> N >> K;
    for(int b = K+1;b <= N;b++){
        ans += (b-K) * (N/b);
        if(N%b >= K) ans += N%b-K+1;
    }
    if(K == 0) ans -= N;
    cout << ans << endl;
    return 0;
}
