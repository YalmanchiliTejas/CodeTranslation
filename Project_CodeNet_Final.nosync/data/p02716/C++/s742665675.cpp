#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n;
vector<int> a;
vector< map<int, long long> > dp;
long long ref(int i, int k){
    auto itr = dp[i].find(k);
    if(itr == dp[i].end()) return -1e18;
    return itr->second;
}
int main(void){
    cin >> n;
    a.assign(n+1, 0);
    for(int i=1;i<=n;i++) cin >> a[i];
    dp.assign(n+1, map<int, long long>());
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[1][1] = a[1];
    for(int i=2;i<=n;i++){
        for(int j=0;j<5;j++){
            int k = (i+1)/2-j;
            if(k < 0) continue;
            long long res = ref(i-1, k);
            int cnt = 0;
            for(int l=i-2;l>=0;l--){
                long long tmp = ref(l, k-1) + a[i];
                if(tmp > res) res = tmp;
                if(++cnt > 5) break;
            }
            dp[i][k] = res;
            // cout << i << " " << k << " " << res << endl;
        }
    }
    cout << dp[n][n/2] << endl;
}
