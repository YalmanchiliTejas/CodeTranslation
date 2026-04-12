#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int graph[8][8] = {0};

int N, M;
int res = 0;
int perm[8];

void permute(int pos, int n){
    for(int i=0; i<N; i++) perm[i] = i;

    do{
        if(perm[0] != 0) continue;
        for(int i=0; i<N-1; i++){
            if(graph[perm[i]][perm[i+1]] == 0) break;
            if(i+1 == N-1) res++;
        }
    }while(next_permutation(perm, perm+N));
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = 1;
        graph[b-1][a-1] = 1;
    }

    permute(0, N);
    cout << res << endl;
}
