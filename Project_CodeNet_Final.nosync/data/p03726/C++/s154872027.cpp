#include <bits/stdc++.h>
using namespace std;

int n,x,y,v[100005],t[100005],f;

vector <int> g[100005];

void DFS(int nod){
    v[nod]=1;
    for(int i : g[nod]){
        if(!v[i]) DFS(i), t[nod]+=(!t[i]);
    }
    if(t[nod]>1) f=1;
}

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> x >> y;
        g[x].push_back(y); g[y].push_back(x);
    }
    DFS(1);
    if(f || !t[1]) cout << "First";
    else cout << "Second";
}
