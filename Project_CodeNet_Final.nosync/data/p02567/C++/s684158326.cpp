#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double PI = 3.1415926535897932384626;
const double EPS = 1e-10;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;

// 一点変更,範囲取得のセグ木
// Mはモノイド, op()とe()を問題によって修正する
typedef ll M;
M op(M m0, M m1){
    return max(m0, m1);
}
M e(){
    return -1;
}
M value;
bool f(M m){
    return m < value;
}
template<typename Monoid>
class SegmentTree{
    std::vector<Monoid> v;
    int _n;
    int size;
    M prodi(int l, int r, int objl, int objr, int index){
        //cerr << l << " " << r << " " << objl << " " << objr << " " << index << " " << v[index] << endl;
        if(l <= objl && objr <= r){
            return v[index];
        }else if(r <= objl || objr <= l){
            return e();
        }
        M ml = prodi(l, r, objl, (objl + objr) / 2, index * 2);
        M mr = prodi(l, r, (objl + objr) / 2, objr, index * 2 + 1);
        return op(ml, mr);
    }

public:
    SegmentTree(){
        SegmentTree(0);
    }
    SegmentTree(int n){
        _n = n;
        size = 1;
        while(size < n) size *= 2;
        size = size * 2;
        for(int i = 0; i < size; i++) v.push_back(e());
    }
    void set(int x, Monoid m){
        assert(0 <= x && x < _n);
        int index = size / 2 + x;
        v[index] = m;
        while(index != 1){
            index = index / 2;
            v[index] = op(v[index * 2], v[index * 2 + 1]);
        }
        /*
        rep(i, size) cerr << v[i] << " ";
        cerr << endl;*/
    }
    Monoid get(int x){
        assert(0 <= x && x < _n);
        return v[size / 2 + x];
    }
    // op(v[l], .. v[r - 1])
    Monoid prod(int l, int r){
        assert(0 <= l && l < r && r <= _n);

        return prodi(l, r, 0, size / 2, 1);
    }

    Monoid all_prod(){
        return prod(0, _n);
    }

    template <bool (*f)(Monoid)> int max_right(int l) {
        return max_right(l, [](Monoid x) { return f(x); });
    }
    template<class F>
    int max_right(int l, F f){
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;

        int index = l + size / 2;
        
        // trueだったすでに確かめた左側のノードの情報を表すMonoid
        Monoid leftm = e();

        do{
            // 枝の右側(index % 2 == 1)になるまで遡る
            while(index % 2 == 0) index = index / 2;
            if(!f(op(leftm, v[index]))){
                //indexがfalseなら左側,右側の順でノードを見る
                //木の末端までしらべる
                while(index < size / 2){
                    index = index * 2;
                    if(f(op(leftm, v[index]))){
                        leftm = op(leftm, v[index]);
                        index++;
                    }
                }
                return index - size / 2;
            }
            leftm = op(leftm, v[index]);
            index++;
        }while((index & -index) != index); // index & -index == index になるのは indexが 1, 2, 4..と2の累乗の時
        return _n;
    }
};

int main(){

    int n, q;
    cin >> n >> q;

    SegmentTree<ll> st(n);

    rep(i, n){
        ll tmp;
        cin >> tmp;

        st.set(i, tmp);
    }

    rep(i, q){
        ll q, a, b;
        cin >> q >> a >> b;

        if(q == 1){
            st.set(a - 1, b);
        }else if(q == 2){
            //cerr << a - 1 << " " << b << endl;
            cout << st.prod(a - 1, b) << endl;
        }else{
            value = b;
            cout << st.max_right(a - 1, f) + 1 << endl;
        }
    }

    return 0;
}
