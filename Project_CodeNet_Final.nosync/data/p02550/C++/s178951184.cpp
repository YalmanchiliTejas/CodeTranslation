
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include<map>
using namespace std;
typedef long long ll;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    ll a = x;
    ll ans = 0;
    map<ll, int> mp;
    vector<ll> fir;
    ll dup = -1;
    for (int i = 0; i < n;i++){
        if(mp[a]){
            dup = a;
            break;
        }
        fir.push_back(a);
        ans += a;
        mp[a] = i;
        a = a * a % m;
        
    }
    if(dup == -1){  //还没重复就完事了
        cout << ans;
    }else{
        ll sum1 = 0;
        for (int i = 0; i < mp[dup];i++)
            sum1 += fir[i];
        int cnt1 = mp[dup];

        ll sum2 = 0;
        for (int i = mp[dup]; i < fir.size();i++)
            sum2 += fir[i];
        int cnt2 = fir.size() - mp[dup];
        //cout << sum1 << ' ' << sum2;
        //cout << cnt1 << ' ' << cnt2;

        ll re = (n - cnt1) / cnt2;
        sum2 *= re;

        int cnt3 = (n - cnt1) % cnt2;
        ll sum3 = 0;
        for (int i = mp[dup]; i < mp[dup] + cnt3;i++)
            sum3 += fir[i];

        cout << sum1 + sum2 + sum3;
    }


        
}