#include<iostream>

using namespace std;

int main() {
    
    size_t mod = 1000000007;
    long long sum = 0,Answer = 0;

    size_t T; cin >> T;
    
    
    for(size_t t = 0; t < T; t++) { 
        long long temp;
        cin >> temp;
        temp %= mod;
        Answer += (temp*sum) % mod;
        Answer %= mod;
        sum += temp;
        sum %= mod;
    }
    
    cout<<Answer;
    
    return 0;
}