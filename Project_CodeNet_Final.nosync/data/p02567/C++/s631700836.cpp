#include<atcoder/all>
#include<iostream>
#include<algorithm>
using namespace std;

int n, q;

int mx(int x, int y){return max(x, y);}
int zero(){return 0;}

int main(){
    cin >> n >> q;
    vector<int> a(n);
    for(auto &elem:a)cin >> elem;
    atcoder::segtree<int,
                     mx,
                     zero>seg(a);

    while(q--){
        int t, x, v, l, r;
        cin >> t;
        if(t == 1){
            cin >> x >> v;x--;
            seg.set(x, v);
        }
        if(t == 2){
            cin >> l >> r;l--,r--;
            cout << seg.prod(l, r+1) << endl;
        }
        if(t == 3){
            cin >> x >> v;x--;
            cout << seg.max_right(x, [&](int x){return x < v;}) + 1<< endl;
        }
    }
}