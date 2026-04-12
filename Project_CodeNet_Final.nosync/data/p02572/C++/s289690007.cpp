#include <iostream>

using namespace std;

int main(){
    int n;
    int mod = 1000000007;
    long long a=0, b=0 , tmp;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        tmp %= mod;
        a += tmp;
        b += tmp*tmp;
        b %= mod;
        a %= mod;
    }
    

    a = a*a%mod;
    a -= b;
    if(a < 0){
        a += mod;
    }
    a *= (mod + 1)/2;
    cout << a%mod << endl;
}
