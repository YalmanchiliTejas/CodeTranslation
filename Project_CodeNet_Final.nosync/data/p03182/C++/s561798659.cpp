#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct LazySegtreeAdd {
    int n;
    T e;
    vector<T> dat, laz;
    typedef function<T(T a, T b)> Func;
    Func f;

    LazySegtreeAdd(int n_input, Func f, T e_input):f(f), e(e_input){
        n = 1;
        while(n < n_input) n <<= 1;
        dat.resize(2*n-1, e);
        laz.resize(2*n-1, 0);
    }

    void initialize(vector<T>& v){
        for(int i=0; i<v.size(); i++) dat[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) dat[i] = f(dat[i*2+1], dat[i*2+2]);
        fill(laz.begin(), laz.end(), 0);
    }

    void eval(int k, int l, int r){
        if(laz[k] == 0) return;
        dat[k] += laz[k];
        if(r-l > 1){
            laz[2*k+1] += laz[k];
            laz[2*k+2] += laz[k];
        }
        laz[k] = 0;
    }

    void add_between(int a, int b, T x){
        add(a, b+1, x, 0, 0, n);
    }

    void add(int a, int b, T x, int k, int l, int r){
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            laz[k] = x;
            eval(k, l, r);
        }else{
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            dat[k] = f(dat[2*k+1], dat[2*k+2]);
        }
    }

    T get_between(int a, int b){
        return query(a, b+1, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r){
        eval(k, l, r);
        if(r<=a || b<=l) return e;
        if(a<=l && r<=b) return dat[k];
        T vl = query(a, b, 2*k+1, l, (l+r)/2);
        T vr = query(a, b, 2*k+2, (l+r)/2, r);
        return f(vl, vr);
    }
};

int L[200000], R[200000], A[200000];
vector<int> L2i[200001], R2i[200001];

int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> L[i] >> R[i] >> A[i];
        L2i[L[i]].push_back(i);
        R2i[R[i]].push_back(i);
    }

    const int64_t INF = 1e18;
    LazySegtreeAdd<int64_t> st(N+1, [](int64_t a, int64_t b){ return max(a, b);}, -INF);
    vector<int64_t> init(N+1, 0);
    st.initialize(init);

    for(int i=1; i<=N; i++){
        int64_t result = st.get_between(0, i-1);
        st.add_between(i, i, result);
        for(int j : R2i[i]) st.add_between(L[j], R[j], A[j]);
    }
    int64_t ans = st.get_between(0, N);
    cout << ans << endl;
    return 0;
}