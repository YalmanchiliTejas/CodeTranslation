#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

#include<atcoder/all>
using namespace atcoder;

int b;

int op(int a,int b){return max(a,b);}
int e(){return -1;}
bool f(int x){ return x < b;}

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    segtree<int,op,e> seg(a);
    while(q--){
        int t,a;
        cin >> t >> a >> b;
        if(t==1){
            --a;
            seg.set(a,b);
        }else if(t==2){
            --a;
            cout << seg.prod(a,b) << endl;
        }else if(t==3){
            --a;
            cout << seg.max_right<f>(a)+1 << endl;
        }
    }
    return 0;
}