#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
typedef unsigned long long ull;

int op(int a, int b){ return max(a, b);}
int e(){return numeric_limits<int>::min();}
int target;
bool f(int v){ return v < target;}

int main()
{
    int N, Q;
    cin >> N >> Q;
    segtree<int, op, e> seg(N);
    int Ai;
    for(int i=0;i<N;i++){
        cin >> Ai;
        seg.set(i, Ai);
    }
    int Ti, X, Y;
    vector<int> res;
    for(int i=0;i<Q;i++){
        cin >> Ti >> X >> Y;
        if(Ti == 1){
            seg.set(X-1, Y);
        }else if(Ti == 2){
            auto ret = seg.prod(X-1, Y);
            res.push_back(ret);
        }else if(Ti == 3){
            target = Y;
            res.push_back(seg.max_right<f>(X-1) + 1);
        }else{ abort();}
    }
    for(auto v : res) cout << v << endl;

    return 0;
}