#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

template<typename T>
using vec2 = vector<vector<T>>;
template<typename T>
using vec3 = vec2<vector<T>>;
template<typename T>
using vec4 = vec3<vector<T>>;
template<typename T>
using vec5 = vec4<vector<T>>;
template<typename T>
using vec6 = vec5<vector<T>>;



int main(){
    int N;cin>>N;
    vector<ll> A;
    vector<ll> sum(N+1);
    ll MOD = 1000000007;
    for(int i = 0;i < N;i++){
        ll a;cin>>a;
        A.push_back(a);
        sum[i+1] = (sum[i] + a)%MOD;
    }
    ll res = 0;
    for(int i = 0;i < N;i++){
        res += (A[i] * (sum[N]-sum[i +1]+MOD)) % MOD;
        res %= MOD;
    }

    cout<<res<<endl;
}