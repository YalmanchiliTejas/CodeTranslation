#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#define rep(i,N) for(long long i=0; i<N; i++)
using namespace std;

long long mod = 1000000007;


auto return_sum(vector<long long> A){
    vector<long long> S(A.size()+1);
    S[0] = 0;
    for(long long i = 0; i < A.size(); i++){
        S[i+1] = (S[i] + A[i]) % mod;
    }
    return S;
}

int main(){
    long long N;
    cin >> N;
    vector<long long> A(N);
    for(long long i=0; i<N; i++){
        cin>>A[i];
    }
    vector<long long> S = return_sum(A);
    
    long long sum=0;
    rep(i,N-1){
        sum += (A[i] *(S[N]-S[i+1] + mod)%mod) % mod;
    }
    cout << sum%mod << endl;
}