#include<bits/stdc++.h>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
int op(int a, int b){
    return max(a, b);
}
int e(){
    return -1;
}
int to;
bool f(int v){
    return v < to;
}
void Main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    For(i,0,n) cin >> a[i];
    segtree<int, op, e> seg(a);
    while(q--){
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        if(t == 1){
            seg.set(x, y);
        }
        else if(t == 2){
            cout << seg.prod(x, y) << endl;
        }
        else if(t == 3){
            to = y;
            cout << seg.max_right<f>(x) + 1 << endl;
        }
    }
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}