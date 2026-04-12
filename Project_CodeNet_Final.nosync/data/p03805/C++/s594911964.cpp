#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
using ll = long long;
using Point = pair<int, int>;
const int INF = (int)1e9;

int N, M;
bool g[8][8];

int main(void){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            g[i][j] = false;
        }
    }

    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        g[--a][--b] = true; g[b][a] = true;
    }

    int arr[8];
    for(int i = 0; i < N; i++) arr[i] = i;
    int res = 0;

    do{
        // for(int i = 0; i < N; i++) cout << arr[i];
        // cout << '\n';

        for(int i = 0; i < N-1; i++){
            if(not g[arr[i]][arr[i+1]]) break;
            if(i == N-2) res++;
        }
    }while(next_permutation(arr+1, arr+N));

    cout << res << '\n';

    return 0;
}