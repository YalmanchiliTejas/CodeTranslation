#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <functional>
#include <cctype>
#include <locale>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<long long,long long> Pll;
#define fout(num) cout << fixed << setprecision(20) << (num) << endl
//s[i]=tolower(s[i]); islower(s[i]); cout << tolower(s[i])はバグ
//vector<vector<ll>> dp(n,vector<ll>(n))
//2-dim:vector<vector<Type>> vv(n, vector<Type>(m, d));
//3-dim:vector<vector<vector<Type>>> vvv(n, vector<vector<Type>>(m, vector<Type>(l, d)));
template<typename T>
struct SegmentTree{
private:
    int n;
    vector<T> node;
public:
    T merge(T x,T y){
        return max(x,y);
    }
    SegmentTree(vector<T> v){
        int sz=(int)v.size();
        n=1; while(n<sz)n*=2;
        node.resize(2*n-1,0);
        for(int i=0;i<sz;i++) node[i+n-1]=v[i];
        for(int i=n-2;i>=0;i--){
            node[i]=merge(node[2*i+1],node[2*i+2]);
        }
    }
    void update(int x,T val){
        x+=(n-1);
        node[x]=val;
        while(x>0){
            x=(x-1)/2;
            node[x]=merge(node[2*x+1],node[2*x+2]);
        }
    }
    T query(int a,int b,int idx=0,int l=0,int r=-1){ /* get [a,b) */
        if(r<0) r=n;
        if(r<=a||b<=l) return 0;
        if(a<=l&&r<=b) return node[idx];
        T vl=query(a,b,2*idx+1,l,(l+r)/2);
        T vr=query(a,b,2*idx+2,(l+r)/2,r);
        return merge(vl,vr);
    };
    int operator[](int k){return node[k+n-1];}
};
signed main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n,query; cin >> n >> query;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    SegmentTree<ll> seg(a);
    while(query--){
        int t; cin >> t;
        if(t==1){
            int x; ll v;
            cin >> x >> v;
            seg.update(x-1,v);
        }else if(t==2){
            int l,r; cin >> l >> r;
            cout << seg.query(l-1,r) << "\n";
        }else{
            int x; ll v;
            cin >> x >> v;
            if(seg.query(x-1,n)<v){
                cout << n+1 << "\n";
                continue;
            }
            if(v<=seg[x-1]){
                cout << x << "\n";
                continue;
            }
            int l=x-1,r=n;
            while(r-l>1){
                int mid=(l+r)/2;
                if(v<=seg.query(x-1,mid+1)) r=mid;
                else l=mid;
            }
            cout << r+1 << "\n";
        }
    }
}


