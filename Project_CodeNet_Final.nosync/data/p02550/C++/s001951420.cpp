/*
 * @Author: AsilenceBTF
 * @Buff: ︿(￣︶￣)︿  芜湖塔台 起飞
 * @Date: 2019-06-20 09:22:24
 * @LastEditTime: 2020-09-21 20:39:52
 */
#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define ALL(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
#define debug(x) cout << "##### " << x << endl; 
typedef long long ll;

// #define cin in
// #define cout out
// ifstream in("in.txt");
// ofstream out("out.txt");

const int N = 2e5 + 105;

ll pre[N], a[N], idx[N];
int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    for(int i = 1; i < N; ++i){
        a[i] = x;
        pre[i] = pre[i - 1] + a[i];
        x = x * x % m;
    }
    if(n < N) cout << pre[n] << endl;
    else{
        ll ans = 0, l = 0, r = 0;
        for(int i = 1; i < N; ++i){
            if(idx[a[i]]){
                l = idx[a[i]], r = i - 1;
                break;
            }
            idx[a[i]] = i;
            --n;
            ans += a[i];
        }
        ans += (pre[r] - pre[l - 1]) * (n / (r - l + 1));
        n %= (r - l + 1);
        for(int i = r + 1; i < N; ++i){
            if(n <= 0) break;
            ans += a[i];
            --n;
        }
        cout << ans << endl;
    }
}