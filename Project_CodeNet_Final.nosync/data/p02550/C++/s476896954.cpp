#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;


int main()
{
    ll n,x,m; cin >> n >> x >> m;
    bool e = false;
    set<ll> s;
    ll p = -1;
    ll a = x;
    for(int i = 0; i < n; i++){
        if(s.find(a) != s.end()){
            p = a;
            break;
        }
        s.insert(a);
        a = (a*a) % m;
    }
    ll ans = 0;
    if(p == -1){
        a = x;
        for(int i = 0; i < n; i++){
            ans += a;
            a = (a*a) % m;
        }
    }else{
        a = x;
        ll sum1 = 0;
        ll cnt1 = 0;
        while(true){
            cnt1++;
            sum1 += a;
            a = (a*a) % m;
            if(a == p) break;
        }
        ll sum2 = 0;
        ll cnt2 = 0;
        while(true){
            cnt2++;
            sum2 += a;
            a = (a*a) % m;
            if(a == p) break;
        }
        ll cycle = (n-cnt1)/cnt2;
        ans = sum1 + cycle * sum2;
        ll res = n - cnt1 - cycle * cnt2;
        for(int i = 0; i < res; i++){
            ans += p;
            p = (p*p)%m;
        }
    }
    cout << ans << endl;
}