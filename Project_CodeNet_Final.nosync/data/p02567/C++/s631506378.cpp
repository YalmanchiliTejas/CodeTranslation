#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

template <typename T>
struct RMQ
{
    int n;
    const T ex = 0; //初期値
    vector<T> dat; //tree本体
    RMQ(vector<T> v){
        int x = 1;
        int i;
        n = v.size();
        while(x < n) x <<= 1;
        n = x; 
        dat.resize(2*n-1, ex);
        for(i = 0;i < v.size();++i){
            dat.at(i + n - 1) = v.at(i);
        }
        for(i = n-2;i >= 0;--i){
            dat.at(i) = calculate(dat.at(2*i+1), dat.at(2*i+2));
        }
    }
    
    T calculate(T a, T b){
        return max(a, b); //最小値
    }
    
    void update(int ind, T x){
        ind += n - 1;
        dat.at(ind) = x;
        while(ind > 0){
            ind = (ind-1)/2;
            dat.at(ind) = calculate(dat.at(2*ind + 1), dat.at(2*ind + 2));
        }
    }
    
    T query(int a, int b){return query_sub(a, b, 0, 0, n);} //[a, b)
    T query_sub(int a, int b, int now, int l, int r){
        if(r <= a || b <= l) return ex;
        else if(a <= l && r <= b) return dat.at(now);
        else{
            T vl = query_sub(a, b, 2*now + 1, l, (l + r)/2);
            T vr = query_sub(a, b, 2*now + 2, (l + r)/2, r);
            return calculate(vl, vr);
        }
    }
    
    int find_rightest(int a, int b, T x) { return find_rightest_sub(a, b, x, 0, 0, n); } //[a, b)でx以下の一番右
    int find_leftest(int a, int b, T x) { return find_leftest_sub(a, b, x, 0, 0, n); } //[a, b)でx以下の一番左
    int find_rightest_sub(int a, int b, T x, int k, int l, int r) {
        if (dat.at(k) < x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn a-1
            return a - 1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            if (vr != a - 1) {  // 右の部分木を見て a-1 以外ならreturn
                return vr;
            } else {  // 左の部分木を見て値をreturn
                return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            }
        }
    }
    int find_leftest_sub(int a, int b, T x, int k, int l, int r) {
        if (dat.at(k) < x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn b
            return b;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            if (vl != b) {  // 左の部分木を見て b 以外ならreturn
                return vl;
            } else {  // 右の部分木を見て値をreturn
                return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            }
        }
    }
};

int main()
{
    ll i,j;
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    RMQ<ll> rmq(a);
    rep(i,q){
        ll t;
        cin >> t;
        if(t == 1){
            ll x,v;
            cin >> x >> v;
            rmq.update(x-1, v);
        }else if(t == 2){
            ll l, r;
            cin >> l >> r;
            cout << rmq.query(l-1, r) << endl;
        }else{
            ll x,v;
            cin >> x >> v;
            ll ans = rmq.find_leftest(x-1, n, v);
            if(ans == x-2) cout << n+1 << endl;
            else cout << ans+1 << endl;
        }
    }

    return 0;
}