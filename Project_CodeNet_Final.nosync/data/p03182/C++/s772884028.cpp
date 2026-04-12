#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

const int INF=1e9;

class SegmentTree
{
 private:
    int n;
    vector<int> node,lazy;
 public:
    SegmentTree(int sz){
        n=1;
        while(n<sz) n*=2;
        node.assign(2*n-1,0);
        lazy.assign(2*n-1,0);
    }
    void update(int a,int b,int x,int k,int l,int r){
        if(a<=l and r<=b) node[k]+=x,lazy[k]+=x;
        else{
            if(lazy[k]!=0) push(k),lazy[k]=0;
            if(check(a,b,l,(l+r)/2)) update(a,b,x,2*k+1,l,(l+r)/2);
            if(check(a,b,(l+r)/2,r)) update(a,b,x,2*k+2,(l+r)/2,r);
            node[k]=max(node[2*k+1],node[2*k+2]);
        }
    }
    int get(int a,int b,int k,int l,int r){
        if(a<=l and r<=b) return node[k];
        else{
            if(lazy[k]!=0) push(k),lazy[k]=0;
            int res=-INF;
            if(check(a,b,l,(l+r)/2)) res=max(res,get(a,b,2*k+1,l,(l+r)/2));
            if(check(a,b,(l+r)/2,r)) res=max(res,get(a,b,2*k+2,(l+r)/2,r));
            return res;
        }
    }
    void push(int k){
        node[2*k+1]+=lazy[k]; node[2*k+2]+=lazy[k];
        lazy[2*k+1]+=lazy[k]; lazy[2*k+2]+=lazy[k];
    }
    bool check(int a,int b,int l,int r){
        return max(a,l)<min(b,r);
    }
    void update(int a,int b,int x){ update(a,b,x,0,0,n); }
    int get(int a,int b){ return get(a,b,0,0,n); }
};

typedef pair<int,int> pint;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,M; cin>>N>>M;
    vector<pair<pint,int>> v;
    for(int i=0;i<M;i++){
        int l,r,a; cin>>l>>r>>a;
        v.push_back({{r,l},a});
    }
    sort(v.begin(),v.end());
    vector<int> l(M),r(M),a(M);
    for(int i=0;i<M;i++){
        l[i]=v[i].first.second;
        r[i]=v[i].first.first;
        a[i]=v[i].second;
    }

    SegmentTree dp(N+1);
    int idx=0;
    for(int i=1;i<=N;i++){
        int x=dp.get(0,i);
        dp.update(i,i+1,x);
        while(idx<M and r[idx]==i){
            dp.update(l[idx],r[idx]+1,a[idx]);
            idx++;
        }
        // for(int i=0;i<=N;i++) cout<<dp.get(i,i+1)<<' '; cout<<endl;
    }
    cout<<dp.get(0,N+1)<<endl;
    return 0;
}