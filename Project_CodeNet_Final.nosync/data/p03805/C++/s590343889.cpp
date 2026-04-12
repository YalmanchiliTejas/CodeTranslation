#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
bool G[10][10];

int main(){
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = G[b][a] = true;
    }
    vector<int> ord(n);
    rep(i,n) ord[i] = i;
    int res = 0;
    do {
        if(ord[0] != 0)break;
        bool ok = true;
        for(int i = 0;i + 1 < n;i++){
            int from = ord[i];
            int to = ord[i+1];
            if(!G[from][to]) ok = false;
        }
        if(ok) res++;
    }
    while (next_permutation(ord.begin(),ord.end()));
    cout << res << endl;
}