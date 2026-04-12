#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N,X,M;
    cin >> N >> X >> M;
    ll cur = X;
    ll cnt = 0;
    ll stop = 0;
    bool flag = 0;
    vector<ll> memo(M,0);
    deque<ll> v;
    while(memo[cur] == 0){
        memo[cur] = 1;
        if(cur == 0){
            flag = 1;
            break;
        }
        cur = (cur*cur) % M;
        stop = cur;
    }
    //ll ini = 0;
    ll sum_b = 0;
    cur = X;
    vector<ll> u;
    ll cnt_b = 0;
    rep(i,M){
        if(cur == stop){
            break;
        }
        u.push_back(cur);
        sum_b += cur;
        cnt_b++;
        cur = (cur*cur)%M;
    }

    ll sum = 0;
    v.push_back(cur);
    cnt = 1;
    sum += cur;
    cur = (cur*cur)%M;
    while(stop != cur){
        v.push_back(cur);
        sum += cur;
        cur = (cur*cur)%M;
        cnt++;
    }
    ll ans = 0;
    if(N <= cnt_b){
        cout << sum_b << endl;
        return 0;
    }
    N -= cnt_b;
    ans = sum_b;
    ll q = N/cnt;
    ll r = N%cnt;
    if(!flag){
        ans += q*sum;
    }else{
        rep(i,min(ll(v.size()),N)){
            ans += v[i];
        }
        cout << ans << endl;
        return 0;
    }
    /*cout << cnt << endl;
    cout << sum << endl;
    cout << sum_b << endl;
    //cout << ini << endl;
    cout << ans << endl;
    cout << r << endl;*/
    rep(i,r){
        ans += v[i];
    }
    cout << ans << endl;
}