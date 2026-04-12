#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> Pi;
int par[100002];
int rk[100002];
 
void init(int n){
    for(int i=0; i<n; i++){
        par[i]=i; rk[i]=0;
    }
}
 
int find(int x){
    if(par[x]==x){
        return x;
    }else{
        return par[x]=find(par[x]);
    }
}
 
void unite(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(rk[x]<rk[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(rk[x]==rk[y]) rk[x]++;
    }
}
 
bool same(int x, int y){
    return find(x)==find(y);
}
int n, m;
ll w[200001];
int a[200001], b[200001];
vector<P> e;
vector<P> g[100001];
bool ok[200001];
vector<int> ed[100001];
bool used[100001];
ll ans[200001];
typedef set<P> SP;
SP* merge(SP* st1, SP* st2){
    if(st1->size()>st2->size()){
		while(!st2->empty()){
			P p=*st2->begin();
			st2->erase(st2->begin());
            auto itr=st1->find(p);
            if(itr!=st1->end()) st1->erase(itr);
            else st1->insert(p);
        }
        return st1;
    }else{
        while(!st1->empty()){
			P p=*st1->begin();
			st1->erase(st1->begin());
            auto itr=st2->find(p);
            if(itr!=st2->end()) st2->erase(itr);
            else st2->insert(p);
        }
        return st2;
    }
}
SP st[100001]; int c;
SP* dfs(int x){
    used[x]=1;
    c++;
	SP* st0=&st[c];
    for(auto p:g[x]){
        int j=p.second, y=p.first;
        if(used[y]) continue;
        SP* st1=dfs(y);
        if(st1->empty()){
            ans[j]=-1;
        }else{
            ans[j]=(*st1->begin()).first;
        }
        st0=merge(st0, st1);
    }
    for(auto j:ed[x]){
        P p=P(w[j], j);
        auto itr=st0->find(p);
        if(itr!=st0->end()){
            st0->erase(itr);
        }else{
            st0->insert(p);
        }
    }
    return st0;
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a[i]>>b[i]>>w[i]; a[i]--; b[i]--;
        e.push_back(P(w[i], i));
    }
    sort(e.begin(), e.end());
    init(n);
    ll sum=0;
    int ct=0;
    for(int i=0; i<m; i++){
        int j=e[i].second;
        int x=a[j], y=b[j];
        if(!same(x, y)){
            unite(x, y);
            ct++;
            sum+=e[i].first;
            g[x].push_back(P(y, j));
            g[y].push_back(P(x, j));
        }else{
            ok[j]=1;
            ed[x].push_back(j);
            ed[y].push_back(j);
        }
    }
    if(ct<n-1){
        for(int i=0; i<m; i++){
            cout<<-1<<endl;
        }
        return 0;
    }
    dfs(0);
    for(int i=0; i<m; i++){
        if(ok[i]){
            cout<<sum<<endl;
        }else if(ans[i]==-1){
            cout<<-1<<endl;
        }else{
            cout<<sum-w[i]+ans[i]<<endl;
        }
    }
    return 0;
}
