#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main(){
    int N;
    cin >> N;
    ll mod = 1e9+7;
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    sum %= mod;
    ll ans = 0;
    for (int i = 0; i < N; i++) ans += mod-A[i]*A[i]%mod;
    ans += sum*sum%mod;
    ans %= mod;
    if (ans%2 == 0) ans /= 2;
    else ans = ans*((mod+1)/2)%mod;
    cout << ans << endl;
	return 0;
}
