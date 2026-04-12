#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384

using namespace std;
using ll =long long;
using P = pair<int,int>;

#include<algorithm>
#define MAX_N 8
bool G[MAX_N][MAX_N] = {false};
int order[MAX_N];

void permutation(int n){
    for(int i=0; i<n; i++){
        order[i]=i;
    }
    
    int res=0;
    do{
        if(order[0] != 0) continue;
        bool ok=true;
        /* ここにpermの処理を書く */
        for(int i=0; i+1<n; i++){
            int from = order[i];
            int to = order[i+1];
            
            if(!G[from][to]) ok=false;
        }
        if(ok) res++;
    }while(next_permutation(order, order+n));
    
    cout << res << endl;
}

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b]=true;
        G[b][a]=true;
    }
    
    permutation(n);
    
    return 0;
}
