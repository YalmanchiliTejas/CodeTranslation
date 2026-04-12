#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n;
    deque<ll> a;
    deque<ll> b;

    cin >> n;
    rep(i, 0, n){
        ll t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end(), greater<ll>());

    ll sum1 = 0, sum2 = 0;
    if(n % 2 == 1){
        rep(i, 0, n){
            if(i <= n / 2 - 1){
                sum1 += a[i] * 2;
            }else if(i <= n / 2 + 1){
                sum1 -= a[i];
            }else{
                sum1 -= a[i] * 2;
            }
        }
        rep(i, 0, n){
            if(i <= n / 2 - 2){
                sum2 += a[i] * 2;
            }else if(i <= n / 2){
                sum2 += a[i];
            }else{
                sum2 -= a[i] * 2;
            }
        }
        cout << max(sum1, sum2) << endl;
    }else{
        rep(i, 0, n){
            if(i <= n / 2 - 2){
                sum1 += a[i] * 2;
            }else if(i <= n / 2 - 1){
                sum1 += a[i];
            }else if(i <= n / 2){
                sum1 -= a[i];
            }else{
                sum1 -= a[i] * 2;
            }
        }
        cout << sum1 << endl;
    }

    return 0;
}
