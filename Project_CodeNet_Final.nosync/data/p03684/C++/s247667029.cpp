#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int parent[N],sz[N];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> xvec,yvec;
    vector<pair<int,pair<int,int>>> evec;
    for(int i = 0; i<n; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        xvec.push_back({x,i});
        yvec.push_back({y,i});
    }
    sort(xvec.begin(),xvec.end());
    sort(yvec.begin(),yvec.end());
    for(int i = 0; i<n-1; i++){
        evec.push_back({xvec[i+1].first-xvec[i].first,{xvec[i].second,xvec[i+1].second}});
        evec.push_back({yvec[i+1].first-yvec[i].first,{yvec[i].second,yvec[i+1].second}});
    }
    for(int i = 0; i<n; i++)
        make_set(i);
    sort(evec.begin(),evec.end());
    long long ans = 0;
    for(auto it:evec){
        int a,b;
        tie(a,b)=it.second;
        if(find_set(a)!=find_set(b)){
            union_sets(a,b);
            ans += it.first;
        }
    }
    printf("%lld\n",ans);
    return 0;
}