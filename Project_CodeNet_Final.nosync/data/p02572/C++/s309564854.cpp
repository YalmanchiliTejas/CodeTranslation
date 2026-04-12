#include<bits/stdc++.h>
using namespace std;

const long long MOD=1000000007;

int main(){
    long long N;
    cin >> N;
    long long A[N+1];
    long long i;
    for(i=1; i<=N; i++){
        cin >> A[i];
    }
    long long sum_from[N+1];
    sum_from[N]=A[N];
    for(i=N-1; i>=1; i--){
        sum_from[i]=sum_from[i+1]+A[i];
        sum_from[i]%=MOD;
    }
    long long ans=0;
    for(i=1; i<N; i++){
        ans+=A[i]*sum_from[i+1];
        ans%=MOD;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}