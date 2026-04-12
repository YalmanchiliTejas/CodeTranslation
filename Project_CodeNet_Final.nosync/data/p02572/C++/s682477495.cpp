#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
static const int MOD = 1e9+7;

int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    ll sum = 0;
    for(int i=0; i<N; i++){
        cin>>A[i];
        sum += A[i];
        sum %= MOD;
    }

    ll ans = 0;
    for(int i=0; i<N; i++){
        sum -= A[i];
        if(sum < 0) sum += MOD;
        ans += A[i] * sum;
        ans %= MOD;
    }

    cout<<ans<<endl;
}