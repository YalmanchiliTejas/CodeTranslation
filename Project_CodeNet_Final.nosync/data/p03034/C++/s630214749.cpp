#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 100005

vector<ll> yakusuu_rekkyo(ll n){
    vector<ll> divisors;
    for(ll i = 1; i <= n; i++){
        if(i * i > n)break;
        if(i * i == n){
            divisors.push_back(i);
            break;
        }else if(n % i == 0){
            divisors.push_back(i);
            divisors.push_back(n/i);
        }   
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

vector<ll> sum[MAX_N], sum2[MAX_N];

int main() {
    int n; cin >> n;
    ll a[n] = {};
    rep(i,n) cin >> a[i];

    srep(i,1,n-1){
        int now = 0;
        ll tmp = 0;
        sum[i].push_back(tmp);
        while(true){
            now += i;
            if(now < n-1){
                tmp += a[now];
                sum[i].push_back(tmp);
            }else{
                break;
            }
        }
    }

    srep(i,1,n-1){
        int now = n-1;
        ll tmp = 0;
        sum2[i].push_back(tmp);
        while(true){
            now -= i;
            if(now >= 0){
                tmp += a[now];
                sum2[i].push_back(tmp);
            }else{
                break;
            }
        }
    }

    ll ans = 0;
    srep(i,1,n-1){
        vector<ll> v = yakusuu_rekkyo(n-1-i);
        int m = v.size();
        rep(j,m){
            int c = v[j];
            if(c >= i) break;
            int b = i - c;
            if(b >= i) continue;
        
            ll loop = (n-1-i) / c;
            ll tmp = sum[c][loop] + sum2[c][loop];

            if(i % c == 0 && i/c <= loop) continue;

            /*
            int now = 0;
            while(true){
                now += i;
                if(now == n - 1) break;
                tmp += a[now];
                now -= b;
                tmp += a[now];
                if(now - i >= 0 && (now-i)%c == 0){
                    tmp = -1;
                    break;
                }
            }
            */
            // cout << i << ' ' << b << ' ' << tmp << endl;
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
    return 0;
}


