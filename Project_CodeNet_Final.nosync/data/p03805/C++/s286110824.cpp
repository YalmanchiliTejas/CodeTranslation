#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    int N, M; cin >> N >> M;
    Graph G(N);
    vector<int> v;
    for(int i=0; i<N; i++){
        v.push_back(i);
    }
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int cnt = 0;
    do{
        for(int i=0; i<N; i++){
            if(i==N-1) cnt++; 
            else if(count(G[v[i]].begin(), G[v[i]].end(), v[i+1])==0){
                break;
            }
        }
    } while (next_permutation(v.begin()+1, v.end()));

    cout << cnt << endl;
}