//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int op(int a,int b){ return max(a,b); }

int e(){ return -1; }

int target;

bool f(int v){ return v<target; }

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    vector<int> a(n,0);
    rep(i,n) cin>>a[i];
    segtree<int,op,e> st{a};
    rep(_,q){
        int t; cin>>t;
        if(t==1){
            int x,v; cin>>x>>v;
            st.set(x-1,v);
        }
        if(t==2){
            int l,r; cin>>l>>r;
            printf("%d\n",st.prod(l-1,r));
        }
        if(t==3){
            int x,v; cin>>x>>v;
            target=v;
            printf("%d\n",st.max_right<f>(x-1)+1);
        }
    }
}