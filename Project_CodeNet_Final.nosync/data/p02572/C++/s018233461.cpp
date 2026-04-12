#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int INF = 1001001001;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    
    ll sum=0;
    ll ans=0;
    int mod = 1000000007;
    rep(i,N){
        cin >> A.at(i);
        sum += A.at(i);
        sum %= mod;
    }
    rep(i,N){
        sum -= A.at(i);
        if(sum<0){
            sum += mod;
        }
        ans += A[i] * sum;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}