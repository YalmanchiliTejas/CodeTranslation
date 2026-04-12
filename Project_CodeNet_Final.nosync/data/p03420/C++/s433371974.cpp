#include <iostream>
using namespace std;
int main(){
    long int N,K;
    cin >> N >> K;
    long int ans = 0;
    if(K==0)
        ans=N*N;
    else{
        for (int b=K+1;b<=N;b++){
            int rem, quo;
            rem = N % b;
            quo = N / b;
            if (rem >= K)
                ans += (b-K) * quo + (rem-K+1);
            else
                ans += (b-K) * quo;
        }
    }
    cout << ans << endl;
}