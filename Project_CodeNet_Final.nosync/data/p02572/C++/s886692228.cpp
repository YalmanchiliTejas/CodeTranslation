#include<bits/stdc++.h>
using Int = long long;
using namespace std;
const Int mod = 1e9 + 7;
int main(){
    int N;
    cin >> N;
    vector<Int>A(N);
    for(auto& e : A) cin >> e;
    auto csum = A;
    for(int i = 1; i < csum.size(); ++i)
        csum[i] += csum[i - 1];
    Int ans = 0;
    for(int i = 0; i < N; ++i){
        Int prev =  csum[i];
        ans += ((csum.back() - prev) % mod) * A[i];
        ans %= mod;
    }
    cout << ans << endl;
}

