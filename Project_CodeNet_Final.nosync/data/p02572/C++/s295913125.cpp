#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int N;
    cin >> N;
    vector<long long> A(N+1),sum(N+1);
    long long mod = 1000000007;
    sum.at(0) = 0;
    for(int i=1;i<=N;i++){
        cin >> A.at(i);
        sum.at(i) = sum.at(i-1) + A.at(i);
    }
    long long ans = 0;
    for(int i=1;i<N;i++){
        ans += ((A.at(i)%mod)*((sum.at(N)-sum.at(i))%mod))%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}