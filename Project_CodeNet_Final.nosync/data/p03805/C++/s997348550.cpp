#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;

int N, M;
vector<int> g[8];

int main(void){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    int ar[8];
    ar[0] = 0;
    for(int i = 1; i < N; i++) ar[i] = i;

    int res = 0;
    do{
        int flag = true;
        for(int i = 0; i < N-1; i++){
            // debug(count(g[ar[i]].begin(), g[ar[i]].end(), ar[i+1]));
            if(count(g[ar[i]].begin(), g[ar[i]].end(), ar[i+1]) == 0) flag = false;
        }

        if(flag) res++;
    }while(next_permutation(ar+1, ar+N));

    cout << res << '\n';

    return 0;
}