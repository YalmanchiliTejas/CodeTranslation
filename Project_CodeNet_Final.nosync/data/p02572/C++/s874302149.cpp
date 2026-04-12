#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define Boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const long MOD = 1000000007;

long long Power(long long a,long long b) {
    long long x=1;
    long long MOD = 1000000007;
    for(;b;b>>=1) {
        if(b&1) x = x*a%MOD;
        a = a*a%MOD;
    }
    return x;
}

long long ModInverse(long long c) {
    return Power(c,MOD-2);
}

void Crack() {
	long n;
    cin >> n;
    vector <long> A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    long long sm=0;
    for(int i=0;i<n;i++) sm += A[i];
    long long ans = 0;
    for(int i=0;i<n;i++) {
        ans = ans + (((sm-A[i])%MOD)*A[i])%MOD;
        ans = ans%MOD;
    }
    ans = (ans*ModInverse(2))%MOD;
    cout << ans << endl;
}

int main() {
	Boost;
    Crack();
	return 0;
}