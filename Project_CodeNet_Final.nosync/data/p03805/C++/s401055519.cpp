#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int N, M; cin >> N >> M; 
    vector<vector<int>> G(N);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> ord(N);
    for(int i=0; i<N; i++) ord[i]=i;
    int res=0;
    do{
        if(ord[0] != 0) continue;
        bool ok=true;
        for(int i=0; i<N-1; i++){
            auto it=find(G[ord[i]].begin(), G[ord[i]].end(), ord[i+1]);
            if(it == G[ord[i]].end()) ok=false;
        }
        if(ok) res++;
    }while(next_permutation(ord.begin(),ord.end()));
    cout << res << endl;
    return 0;
}