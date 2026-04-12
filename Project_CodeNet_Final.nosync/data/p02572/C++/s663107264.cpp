#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

#define ll long long

using namespace std;

const ll mod = 1e9+7;

int main()
{
    int N;

    cin >> N;

    vector <ll int> A(N+3), B(N+3, 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = A[i]%mod;
    }


    ll ans = 0;



    for(int i = N - 2; i > 0; i--) {
       B[i] = (B[i] + B[i+1])%mod;;
    }

    for(int i = 1; i < N; i++) {
        ans = (ans + (B[i]*A[i-1]) % mod)%mod;
    }

    cout << ans;


    return 0;
}