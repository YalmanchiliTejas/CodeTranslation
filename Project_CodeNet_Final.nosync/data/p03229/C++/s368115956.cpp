#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    vector<i64> v;
    for(int i=0;i<n;++i){
        i64 a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    i64 ans = 0;
    if(n%2){
        for(int i=0;i<n/2;++i)ans -= v[i]*2;
        for(int i=n/2;i<n;++i)ans += v[i]*2;
        ans -= v[n/2];
        ans -= v[n/2+1];
        i64 tmp = 0;
        for(int i=0;i<=n/2;++i)tmp -= v[i]*2;
        tmp += v[n/2];
        tmp += v[n/2-1];
        for(int i=n/2+1;i<n;++i)tmp += v[i]*2;
        ans = max(ans, tmp);
    }else{
        for(int i=0;i<n/2;++i)ans -= v[i]*2;
        ans += v[n/2-1];
        for(int i=n/2;i<n;++i)ans += v[i]*2;
        ans -= v[n/2];
    }
    cout << ans << endl;

    return 0;
}