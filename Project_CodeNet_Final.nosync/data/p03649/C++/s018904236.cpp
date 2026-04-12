#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll> a(n);rep(i,n){cin >> a.at(i);}
    priority_queue<ll> pq;
    rep(i,n){pq.push(a[i]);}
    ll cnt=0;
    while(pq.top()+cnt>=n){
        ll top = pq.top();
        pq.pop();
        DEBUG{
            printf("top: %lld, cnt: %lld\n", top, cnt);
        }
        ll sub = (top+cnt-n-1)/(n+1)+1;
        top -= (n+1)*sub;
        cnt += sub;
        pq.push(top);
    }
    cout << cnt << endl;
    return 0;
}
