/*
 * @Author: AsilenceBTF
 * @Buff: ︿(￣︶￣)︿  芜湖塔台 起飞
 * @Date: 2019-06-20 09:22:24
 * @LastEditTime: 2020-08-30 15:10:14
 */
// #include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

#define sz(x) int(x.size())
#define ALL(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
typedef long long ll;

const int MOD = 1e9 + 7;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    ll ans = 0;
    vector<ll> pre(n + 2);
    for(int i = 1; i <= n; ++i){
        cin >> pre[i];
        if(i == 1) continue;
        ans = (ans + pre[i]*pre[i - 1] % MOD) % MOD;
        pre[i] = (pre[i] + pre[i - 1]) % MOD;
    }
    cout << ans << endl;
    // system("pause");    
}