#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,K,ans=0;
    cin >> N >> K;

    if(K==0){
        ans -= N;
    }
    for(int b=1;b<=N;b++){
        long long int p = N/b,r = N%b;
        ans += p*max((long long int)0,b-K);
        ans += max((long long int)0,r-K+1);
    }

    cout << ans << endl;
}