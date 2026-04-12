#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int Nmax = 8; 
bool node[Nmax][Nmax];

int DFS(int v, int N, vector<bool>visit){
    bool all_visit = true;
    for(int i=0; i<N; i++){
        if(visit.at(i) == false) all_visit = false;
    }
    if(all_visit)return 1;

    int ans = 0;

    for(int i=0; i<N; i++){
        if(visit.at(i)) continue;
        if(node[v][i] == false) continue;

        visit[i] = true;
        ans += DFS(i,N,visit);
        visit[i] = false; 
    }
    return ans;
}

int main(){
    int N,M;
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        node[a-1][b-1] = node[b-1][a-1] = true;
    }
    
    vector <bool>visit(N,false);
    visit.at(0)=true;

    cout << DFS(0, N, visit)<<"\n";

    return 0;
}