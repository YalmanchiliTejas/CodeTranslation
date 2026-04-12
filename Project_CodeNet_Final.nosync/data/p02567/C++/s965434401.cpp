#include <iostream>
#include <vector>
using namespace std;
//区間和を書いてます
struct segK{//非再帰
    int n;
    long long MIN;
    vector<long long> dat;
    segK(int n_){
        n = 1;
        MIN = -1;
        while(n < n_) n *= 2;
        dat.resize(2 * n);
        for(int i = 1; i < 2 * n; i++) dat[i] = MIN;
    }
    void update(int k, long long a){
        k += n;
        dat[k] = a;
        while(k > 0){
            k >>= 1;
            dat[k] = max(dat[k << 1 | 0], dat[k << 1 | 1]);
        }
    }
    long long query(int l, int r){
        long long res = 0;
        l += n;
        r += n;
        while(r > l){
            if(l & 1) res = max(res, dat[l++]);
            if(r & 1) res = max(res, dat[--r]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
    int bin(int l, long long v) {
        l += n;
        long long zero = -1;
        do {
            while (l % 2 == 0) l >>= 1;
            if (dat[l] >= v) {
                while (l < n) {
                    l = (2 * l);
                    if (dat[l] < v) {
                        zero = max(zero, dat[l]);
                        l++;
                    }
                }
                return l - n;
            }
            zero = max(zero, dat[l]);
            l++;
        } while ((l & -l) != l);
        return -1;
    }
};

int main(){
    int N, Q;
    cin >> N >> Q;
    segK segtree(N);
    for(int i = 0; i < N; i++){
        long long a;
        cin >> a;
        segtree.update(i, a);
    }
    for(int i = 0; i < Q; i++){
        int t, x, v;
        cin >> t >> x >> v;
        x--;
        if(t == 1) segtree.update(x, v);
        else if(t == 2) {
            long long ans = segtree.query(x, v);
            cout << ans << endl;
        }
        else if(t == 3){
            int ans = segtree.bin(x, v);
            if(ans < x) cout << N + 1 << endl;
            else cout << ans + 1 << endl;
        }
    }
}