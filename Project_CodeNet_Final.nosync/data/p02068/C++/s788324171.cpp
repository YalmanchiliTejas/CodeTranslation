#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a;
map<long long,long long> mp;

long long solve();

int main(){
    cin >> n;
    a.resize(n);
    for(int i = 0;i < n;++i)cin >> a[i];
    cout << solve() << endl;
    return 0;
}

long long solve(){
    for(int i = 0;i < n;++i){
        long long x = a[i];
        for(long long j = 2;j * j <= a[i];++j)
            if(x % j == 0){
                while(x % j == 0)x /= j;
                mp[j] += a[i];
            }
        if(x > 1)mp[x] += a[i];
    }
    long long ans = 0;
    for(auto now : mp)ans = max(ans,now.second);
    return ans;
}
