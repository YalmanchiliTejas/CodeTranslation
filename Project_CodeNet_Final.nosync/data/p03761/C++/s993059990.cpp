#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e18;

int main(){
    ll n;
    cin >> n;
    vector<ll> alpha(26,INF),buf(26);
    rep(i,n){
        string s;
        cin >> s;
        ll m=s.length();
        rep(j,m){
            ll num=s[j]-'a';
            buf[num]++;
        }
        rep(j,26){
            alpha[j]=min(alpha[j],buf[j]);
            buf[j]=0;
        }
    }
    rep(i,26){
        char c='a'+i;
        rep(j,alpha[i]){
            cout << c;
        }
    }
    cout << endl;
    return 0;
}