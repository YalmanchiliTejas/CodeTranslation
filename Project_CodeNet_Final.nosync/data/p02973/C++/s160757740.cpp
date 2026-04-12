#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        v.push_back(a);
    }

    vector<int> dp(n+1, -1);
    dp[1] = v[0];
    for(int i=1;i<n;++i){
        int valid = n, invalid = 0;
        while(abs(valid-invalid) > 1){
            int mid = (valid + invalid) / 2;
            if(v[i] > dp[mid])valid = mid;
            else invalid = mid;
        }
        dp[valid] = v[i];
    }

    int ans = 0;
    for(int i=1;i<=n;++i){
        if(dp[i] != -1)ans = i;
    }

    cout << ans << endl;

    return 0;
}