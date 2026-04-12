#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
struct SegTree{
    int n;
    vector <pair <int,int> > node;
    SegTree(vector <int> v){
        int sz = v.size();
        n = 1;
        while(n<sz) n*=2;
        node.resize(2*n-1, {-INF,-INF});
        for(int i=0; i<sz; i++) node[i+n-1] = {v[i],i}; //一番下側
        for(int i=n-2;i>=0;i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }
    int getnum(int p){
        return node[n-1+p].F;
    }
    int geti(int p){
        return node[n-1+p].S;
    }
    void update(int number, int val){
        number += n-1;
        node[number].F = val;
        while(number>0){
            number=(number-1)/2;
            node[number] = max(node[number*2+1], node[number*2+2]);
        }
    }
    void add(int number, int val){
        number += n-1;
        node[number].F += val;
        while(number>0){
            number=(number-1)/2;
            node[number] = max(node[number*2+1], node[number*2+2]);
        }
    }
    pair <int,int> getmax(int a, int b, int k=0, int l = 0, int r = -1){ //0~n
        
        if(r<0) r=n;
        if(r<=a||b<=l) return {-INF,-INF};
        if(a <= l&& r<=b) return node[k];
        pair <int,int>  vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        pair <int,int>  vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
    void showall(){
        for(int i=0;i<2*n-1;i++)cout<<node[i].F<<'&'<<node[i].S<<endl;
    }
};

signed main(void){
    int n; cin>>n;
    vector <int> a(n); 
    rep(i,n) cin>>a[i];
    SegTree seg(a);
    int ans = 0;
    while(1){
        auto tmp = seg.getmax(0,n);
        if(tmp.F <= n-1) break;
        int add = tmp.F/n;
        tmp.F -= n*add;
        rep(i,n){
            if(i==tmp.S) seg.update(tmp.S, tmp.F);
            else seg.add(i, add);
        }
        ans += add;
    }
    cout<<ans<<endl;
    
}
