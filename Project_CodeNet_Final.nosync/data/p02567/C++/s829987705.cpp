#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

template <typename T>
struct segtree{
    int n;
    T UNIT;
    vector<T> dat;
    segtree(int n_, T unit){
        UNIT = unit;
        n = 1;
        while(n < n_) n *= 2;
        dat = vector<T>(2*n);
        for(int i = 0; i < 2*n; i++) dat[i] = UNIT;
    }

    T calc(T a, T b){
        T ans;
        ans = max(a, b);
        return ans;
    }
    void insert(int k, T a){
        dat[k+n-1] = a;
    }
    void update_all(){
        for(int i = n-2; i >= 0; i--){
            dat[i] = calc(dat[i*2+1], dat[i*2+2]);
        }
    }
    //k番目の値(0-indexed)をaに変更
    void update(int k, T a){
        k += n-1;
        dat[k] = a;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = calc(dat[k*2+1], dat[k*2+2]);
        }
    }

    //[a, b)
    //区間[a, b]へのクエリに対してはquery(a, b+1)と呼ぶ
    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return UNIT;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = query(a, b, k*2+1, l, (l+r)/2);
            T vr = query(a, b, k*2+2, (l+r)/2, r);
            return calc(vl, vr);
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q;
    cin >> n >> q;
    segtree<int> sgt(n, 0);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        sgt.update(i, a);
    }
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 1){
            int x, v; cin >> x >> v; x--;
            sgt.update(x, v);
        }
        if(t == 2){
            int l, r; cin >> l >> r; l--; r--;
            cout << sgt.query(l, r+1) << endl;
        }
        if(t == 3){
            int x, v; cin >> x >> v; x--;
            if(sgt.query(x, x+1) >= v){
                cout << x+1 << endl;
                continue;
            }
            if(sgt.query(x, n) < v){
                cout << n+1 << endl;
                continue;
            }
            int l = x, r = n-1;
            while(r-l > 1){
                int c = (l+r)/2;
                if(sgt.query(x, c+1) >= v) r = c;
                else l = c;
            }
            cout << r+1 << endl;
        }
    }
}