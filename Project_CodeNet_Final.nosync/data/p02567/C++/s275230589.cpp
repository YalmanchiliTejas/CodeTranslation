#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define int long long
constexpr long long INF = numeric_limits<long long>::max() / 2;
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
using Graph = vector<vector<int>>;


int op(int a,int b){
    return max(a,b);
}
int e(){
    return -1;
}
int target;

bool f(int v){
    return v<target;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N,Q;
    cin>>N>>Q;
    int A[N];
    segtree<int,op,e> seg(N);
    rep(i,N){
        cin>>A[i];
        seg.set(i,A[i]);
    }

    rep(i,Q){
        int t,x,v;
        cin>>t>>x>>v;
        if(t==1){
            x--;
            seg.set(x,v);
        }else if(t==2){
            x--;
            int ans=seg.prod(x,v);
            cout<<ans<<endl;
        }else{
            x--;
            target=v;
            cout<<seg.max_right<f>(x)+1<<endl;

        }
    }


}
