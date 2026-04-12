
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#define PIE 3.14159265358979
#define MAX_N 16
#define rep(i,n) for(int i = 0;i < (n);i++)
#define show(x) cout<<(#x)<<":"<<x<<" ";
#define showl(x) cout<<(#x)<<":"<<x<<endl;

using namespace std;
typedef long long ll;

const ll inf = 5e14;

struct segtree{
    int sz;
    vector<ll> node,lazy;
    ll def;

    segtree(int n, ll val){
        sz = 1;
        while(sz<n)sz *= 2;
        node.resize(2*sz-1,val);
        lazy.resize(2*sz-1,0);
        def = -inf;
    }
    
    void debug(){
        cout<<"[node]"<<endl;
        for(int i = 0;i < sz;i++){
            cout<<"["<<i<<"]:"<<getmax(i,i+1)<<" ";
        }
        cout<<endl;
    }
    
    void eval(int k){
        node[k]+=lazy[k];
        if(k<sz-1){
            lazy[2*k+1]+=lazy[k];
            lazy[2*k+2]+=lazy[k];}
        lazy[k]=0;
    }
    
    ll getmax(int x,int y,int l = 0,int r = -1,int k = 0){//[x,y)の最小値を求める

        if(r<0)r=sz;
        eval(k);
        if(r<=x||y<=l)
            return def;
        if(x<=l&&r<=y)
            return node[k];
        else{
            int mid = (l+r)/2;
            return max(getmax(x,y,l,mid,k*2+1),getmax(x,y,mid,r,k*2+2));
        }
    }
    
    void add(int x,int y,ll val,int l=0,int r = -1,int k = 0){
        if(r<0)r=sz;
        eval(k);
        if(r<=x||y<=l){return;}
        if(x<=l&&r<=y){
            lazy[k]+=val;
            eval(k);
        }else{
            int mid = (l+r)/2;
            add(x,y,val,l,mid,k*2+1);
            add(x,y,val,mid,r,k*2+2);
            node[k]=max(node[k*2+1],node[k*2+2]);
        }
    }
};

int main(){
    int N,M;
    vector<int> L,R,a;
    vector<pair<int,int> > add,del;//place,index;
    cin>>N>>M;
    segtree seg(N+1,0);
    L.resize(M),R.resize(M),a.resize(M),add.resize(M),del.resize(M);
    rep(i,M){
        cin>>L[i]>>R[i]>>a[i];
        R[i]++;
        add[i].first = L[i];
        del[i].first = R[i];
        add[i].second = del[i].second = i;
    }
    sort(add.begin(),add.end());
    sort(del.begin(),del.end());
    auto itadd= add.begin(),itdel = del.begin();
    ll ans = 0;
    for(int i = 1;i <= N;i++){
        while(itadd!=add.end()&&itadd->first<=i){
            if(itadd==add.end())break;
            if(itadd->first==i){
                seg.add(0,i,a[itadd->second]);
            }
            itadd++;
        }
        
        while(itdel!=del.end()&&itdel->first<=i){
            if(itdel==del.end())break;
            if(itdel->first==i){
                seg.add(0,L[itdel->second],-a[itdel->second]);
            }
            itdel++;
        }
        
        ll val = seg.getmax(0,i);
        ans = max(ans,val);
        seg.add(i,i+1,val);
    }
    cout<<ans<<endl;
}
