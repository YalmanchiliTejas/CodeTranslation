/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << "\n"

void solve(){
    ll N,X,M;
    cin >> N >> X >> M;
    if(X == 0){
        print(0);
    }else if(X == 1){
        print(N);
    }else{
        vector<ll> v;
        map<ll,ll> mp;
        ll cur = X;
        ll pos = -1;
        ll length = -1;
        ll end_pos = -1;
        rep(i,0,N){
            if(mp[cur] > 0){
                // debug(i);
                pos = mp[cur];
                // debug(pos);
                // debug(cur);
                length = i - pos + 1;
                end_pos = i;
                break;
            }
            mp[cur] = i+1;
            v.push_back(cur);
            cur = cur * cur % M;
        }
        if(end_pos == -1){
            ll ans = 0;
            for(auto &e: v){
                ans += e;
            }
            print(ans);
            return;
        }
        // printa(v, v.size());
        ll ans = 0;
        rep(i,0,pos-1){
            ans += v[i];
        }
        ll repeat = 0;
        rep(i,pos-1, end_pos){
            repeat += v[i];
        }
        ll kaisuu = (N - (pos-1)) / length;
        ll amari = (N - (pos-1)) % length;
        ans += repeat * kaisuu;
        rep(i,pos-1,pos-1+amari){
            ans += v[i];
        }
        print(ans);

    }

    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}