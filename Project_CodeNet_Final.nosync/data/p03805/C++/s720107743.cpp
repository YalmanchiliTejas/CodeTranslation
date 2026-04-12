#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

bool G[10][10];

int main(){
    int N, M; cin >> N >> M;
    rep(i,M){
        int a, b; cin >> a >> b; a--, b--;
        G[a][b] = G[b][a] = true;
    }

    vector<int> permutation(N);
    iota(begin(permutation), end(permutation), 0);

    int res = 0;
    do{
        if(permutation[0] != 0) break;

        bool ok = true;
        for (int i = 0; i+1 < N; i++)
        {
            int from = permutation[i];
            int to = permutation[i+1];
            if(!G[from][to]) ok = false;
        }
        if(ok) ++res;
    }while(next_permutation(begin(permutation), end(permutation)));

    cout << res << endl;
}