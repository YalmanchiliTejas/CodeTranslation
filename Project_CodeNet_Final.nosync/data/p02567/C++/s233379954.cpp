#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int op(int a,int b){return max(a,b);}
int e(){return -1;}
int target;
bool f(int a){return target>a;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vec A(n);
    rep(i,n) cin>>A[i];
    segtree<int,op,e> B(n);
    rep(i,n) B.set(i,A[i]);
    rep(query,q){
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1) B.set(a-1,b);
        if(t==2) cout<<B.prod(a-1,b)<<"\n";
        if(t==3) target=b,cout<<B.max_right<f>(a-1)+1<<"\n";
    }
}