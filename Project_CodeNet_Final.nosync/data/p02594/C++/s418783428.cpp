#include <bits/stdc++.h>
using namespace std;

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
    int x;
    cin >> x;
    if(x >= 30){
        cout << "Yes" << endl;
    }else{
        cout << "No"<< endl;
    }
}