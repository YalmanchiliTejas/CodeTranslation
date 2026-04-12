#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int mod = 1e9 + 7, maxn = 2e5 + 5;
long long nums[maxn], presum[maxn];

int main() {
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    presum[0] = nums[0];
    long long ans = 0;
    for(int i = 1; i < n; i++){
        ans = (ans + (nums[i] * presum[i-1]) % mod) % mod;
        presum[i] = (presum[i-1] + nums[i]) % mod;
    }
    cout<<ans<<endl;
}
