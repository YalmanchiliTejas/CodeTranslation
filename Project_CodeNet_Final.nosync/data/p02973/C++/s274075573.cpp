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
    cin >> n;

    ll a[n];
    rep(i, 0, n){
        cin >> a[i];
    }

    deque<ll> dq;
    rep(i, 0, n){
        ll idx = lower_bound(dq.begin(), dq.end(), a[i]) - dq.begin();
        if(idx == 0){
            dq.push_front(a[i]);
        }else{
            dq[idx - 1] = a[i];
        }
    }

    cout << dq.size() << endl;
    return 0;
}
