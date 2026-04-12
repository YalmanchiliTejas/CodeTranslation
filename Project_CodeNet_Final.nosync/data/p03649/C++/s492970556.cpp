#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

bool check(const vector<i64> &v){
    i64 n = v.size();
    for(auto e: v){
        if(e >= n)return false;
    }
    return true;
}

int main(){
    i64 n;
    cin >> n;
    vector<i64> v;
    for(int i=0;i<n;++i){
        i64 a;
        cin >> a;
        v.push_back(a);
    }
    i64 ans = 0;
    while(!check(v)){
        i64 sum = 0;
        for(auto e: v){
            sum += e / n;
        }
        ans += sum;
        for(auto &e: v){
            i64 tmp = e / n;
            e -= tmp * n;
            e += sum - tmp;
        }
    }
    cout << ans << endl;

    return 0;
}
