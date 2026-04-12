#include <iostream>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 
int main() {
    int N;
    cin >> N;
    ll A[N]; ll s= 0;  ll sum = 0;

    rep(i, N) cin >> A[i]; for (int i = 0; i < N; i++) {s += A[i];}
    for (int i = 0; i < N - 1; i++) {
        s -= A[i];
        sum += (A[i] * (s % 1000000007LL)) % 1000000007LL;
        sum = (sum % 1000000007LL);
        
    }
    cout << sum;
    return 0;
}