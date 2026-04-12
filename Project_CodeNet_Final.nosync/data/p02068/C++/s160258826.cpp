#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

void solve(i64 n, map<i64, i64> &mp){
    i64 m = n;
    for(i64 i=2;i*i<=n;++i){
        if(n % i == 0)mp[i] += m;
        while(n % i == 0){
            n /= i;
        }
    }
    if(n != 1)mp[n] += m;
}

int main(){
    i64 n;
    cin >> n;
    vector<i64> v;
    for(i64 i=0;i<n;++i){
        i64 a;
        cin >> a;
        if(a == 1)continue;
        v.push_back(a);
    }

    map<i64, i64> mp;
    for(auto e: v){
        solve(e, mp);
    }
    i64 ans = 0;
    for(auto e: mp){
        ans = max(ans, e.second);
    }

    cout << ans << endl;

    return 0;
}
