#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isprime(int n){
    double rootn = sqrt(n);
    if (n < 2){
        return false;
    }
    else if (n == 2){
        return true;
    }
    else if (n % 2 == 0){
        return false;
    }
    else{
        for(int i = 3; i <= rootn; i += 2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
}

// 空のベクトルを二つ渡す。N (>=2) 以下の素数を primes に順番に入れる。
void prime_vectors(int N, vector<int>& primes, vector<bool>& is_prime){
    primes = {};
    is_prime = {};
    for(int i=0; i<=N; i++){
        is_prime.push_back(true);
    }

    primes.push_back(2);
    for(int j=4; j<=N; j+=2){
        is_prime[j] = false;
    }

    int i;
    for(i=3; i*i<=N; i+=2){
        if(!is_prime[i]) continue;
        primes.push_back(i);
        for(int j=2*i; j<=N; j+=i){
            is_prime[j] = false;
        }
    }

    for(; i<=N; i+=2){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
}

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int X;
    cin >> X;
    if(X >= 30){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}