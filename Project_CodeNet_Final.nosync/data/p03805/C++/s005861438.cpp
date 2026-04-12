#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define mp make_pair
#define mt make_tuple
typedef long long ll;
using namespace std;

bool G[8][8];
int N,M,ans;
int order[8] = {0,1,2,3,4,5,6,7};

int check(int* v){
    rep(i,N-1){
        if(!G[v[i]][v[i+1]])return false;
    }
    return true;
}

int main(void){
    cin >> N >>M;
    rep(i,M){
        int u,v;
        cin >> u >> v;
        u--;v--;
        G[u][v] = G[v][u] = true;
    }
    
    do{if(check(order))ans++;}while(next_permutation(order+1,order+N));    
    cout << ans << endl;
}
