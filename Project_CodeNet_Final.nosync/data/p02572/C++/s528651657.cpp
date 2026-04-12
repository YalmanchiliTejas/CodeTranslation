#include <bits/stdc++.h>
#define mod 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, i, A[200001], sum=0, ans=0;

    cin >> N;

    for(i=1; i<=N; i++){
        cin >> A[i];
        sum += A[i];
        sum %= mod;
    }

    for(i=1; i<=N-1; i++){
        sum -= A[i];
        if(sum<0) sum += mod;
        ans += ((A[i]*sum) % mod);
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}