#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int modPow(long long int a, long long int n){//繰り返し自乗法(a^n mod p)。計算量 O(logN)
    long long int p = pow(10, 9) + 7;//任意のp(素数) modのやつで使える 
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return a % p;
    }
    if (n % 2 == 1){ 
        return (a * modPow(a, n - 1)) % p;
    }      
    long long t = modPow(a, n / 2);
    return (t * t) % p;
}

int main(){
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    vector<long long int> b(n - 1);
    long long int res = 0;
    long long int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
        sum = (sum + a.at(i)) % mod;
    }
    for(int i = 0; i < n - 1; i++){
        b.at(i) = (sum - a.at(i)) % mod;
        sum -= a.at(i);
        // cout << b.at(i) << endl;
        if(b.at(i) < 0){
            b.at(i) += mod;
        }
    }

    long long int tmp = 0;
    for(int i = 0; i < n - 1; i++){
        tmp = (a.at(i) * b.at(i)) % mod;
        res = (res + tmp) % mod;
        /*
        for(int j = i + 1; j < n; j++){
            tmp = a.at(i) * a.at(j) % mod;
            res = (res + tmp) % mod;
        }
        */
    }
    cout << res << endl;

}