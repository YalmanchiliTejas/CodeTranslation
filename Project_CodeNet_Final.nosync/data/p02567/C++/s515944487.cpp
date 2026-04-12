#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using ll = long long;

int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    atcoder::segtree<int, op, e> st(N);
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        st.set(i, a);
    }
    for(int j=0; j<Q; j++)
    {
        int t, x, v;
        cin >> t >> x >> v;
        if(t == 1) st.set(x - 1, v);
        else if(t == 2) cout << st.prod(x - 1, v) << '\n';
        else if(t == 3){
            auto f = [v](int a) -> bool { return a < v; };
            cout << st.max_right<decltype(f)>(x - 1, f) + 1 << '\n';
        }
    }

    return 0;
}
