#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    const long long int mod =1000000007;
    long int N;
    cin >> N;
    
    vector<long long int> A(N,0);
    rep(i,N) {
        cin >> A.at(i);
    }

    long long int sum1 = 0;
    long long int sum2 = 0;

    rep(i,N) {
        sum1+= A.at(i)%mod;
        sum2+= A.at(i)*A.at(i)%mod;
    }

    long long int sum = 0;
    sum = ((sum1%mod)*(sum1%mod) -sum2%mod)%mod;
    
    if(sum<0){
      sum+mod;
    }
    cout << (sum * 500000004)%mod << endl;
}