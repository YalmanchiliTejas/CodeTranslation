#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> cnt(m, 0);
    ll ind=1, size, check;
    ll now = x;
    ll res = 0;
    while(1){
        if (ind > n) {
            size = n;
            check = n+1;
            break;
        }
        if(cnt[now]==0){
            res += now;
            cnt[now] = ind;
            ind++;
            now = (now * now) % m;
        }else{
            size = ind - cnt[now];
            check = cnt[now];
            break;
        }
        
    }
    for(ll i=0;i<m;i++){
        if(cnt[i]>=check){
            if(cnt[i]-check<(n-check+1)%size){
                res += i * ((n-check+1) / size);
            }else{
                res += i * (((n-check+1) / size) - 1LL);
            }
        }
    }
    cout << res << endl;
    return 0;
}