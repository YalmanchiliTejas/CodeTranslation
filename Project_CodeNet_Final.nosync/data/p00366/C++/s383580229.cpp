#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

vector<i64> divisor(i64 n) {
    vector<i64> res;
    for (i64 i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    int tmax = 0;
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        v.push_back(t);
        tmax = max(tmax, t);
    }
    auto div = divisor(tmax);
    sort(div.begin(), div.end());

    int ans = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<div.size();++j){
            if(v[i] <= div[j]){
                ans += abs(div[j]-v[i]);
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

