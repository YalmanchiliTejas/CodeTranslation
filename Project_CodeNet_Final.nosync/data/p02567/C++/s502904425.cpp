#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Segtree {
    int n, n_org;
    T e;
    vector<T> dat;
    typedef function<T(T a, T b)> Func;
    Func f;

    Segtree(){}
    Segtree(int n_input, Func f_input, T e_input){
        initialize(n_input, f_input, e_input);
    }
    void initialize(int n_input, Func f_input, T e_input){
        n_org = n_input;
        f = f_input;
        e = e_input;
        n = 1;
        while(n < n_input) n <<= 1;
        dat.assign(2*n-1, e);
    }

    void build(vector<T>& A){
        for(int k=0; k<int(A.size()); k++) dat[k+n-1] = A[k];
        for(int k=n-2; k>=0; k--) dat[k] = f(dat[2*k+1], dat[2*k+2]);
    }

    void update(int k, T a){
        k += n - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1)/2;
            dat[k] = f(dat[2*k+1], dat[2*k+2]);
        }
    }

    T get(int k){
        return dat[k+n-1];
    }

    T between(int a, int b){
        return query(a, b+1, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return e;
        if(a<=l && r<=b) return dat[k];
        T vl = query(a, b, 2*k+1, l, (l+r)/2);
        T vr = query(a, b, 2*k+2, (l+r)/2, r);
        return f(vl, vr);
    }

    // [S, t] が条件checkを満たす最大のtを求める
    int bisect(int S, function<bool(T a)> check){
        T val = get(S);
        int k = S+n-1, l = S, r = S+1;
        while(true){
            while(k%2) k = (k-1)/2, r += r-l;
            T val2 = f(val, dat[k]);
            if(check(val2)){
                if(r == n) return n_org-1;
                val = val2;
                k++;
                int d = r-l;
                l += d, r += d;
            }else{
                break;
            }
        }
        while(k<n-1){
            T val2 = f(val, dat[2*k+1]);
            if(check(val2)){
                val = val2;
                k = 2*k+2;
                l = (l+r)/2;
            }else{
                k = 2*k+1;
                r = (l+r)/2;
            }
        }
        return min(l, n_org)-1;
    }
};

int main(){
    int N, Q;
    cin >> N >> Q;
    Segtree<int> st(N+1, [](int a, int b){ return max(a, b); }, -1);
    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        st.update(i, a);
    }
    while(Q--){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            st.update(a, b);
        }else if(t == 2){
            cout << st.between(a, b) << endl;
        }else{
            cout << st.bisect(a, [&](int x){ return x < b; })+1 << endl;
        }
    }
    return 0;
}
