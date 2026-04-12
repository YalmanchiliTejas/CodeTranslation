
#include<iostream>
#include<cstdio>
using namespace std;

int N, K;

int main(){
    cin >> N >> K;
    long long ans = 0;
    for(int b = K+1; b <= N; b++){
        ans += (N/b) * (b-K) + max(0, (N%b) - K + 1);
    }
    if(K == 0){
        ans -= N;
    }
    cout << ans << endl;
}


            