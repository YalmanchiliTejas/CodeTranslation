#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout.precision(12);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    
    int N, M;
    cin >> N >> M;
    bool edge[9][9];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            edge[i][j] = false;
        }
    }
    for(int i=0;i<M;i++){
       int a, b;
       cin >> a >> b;
       edge[a][b] = edge[b][a] = true;
    }

    int p[8];
    iota(p, p+8, 1);
    int ans = 0;

    do{
        for(int i=0;i<N-1;i++){
            if(!edge[p[i]][p[i+1]]) goto next;
        }
        ans++;
        next: ;
    }while(next_permutation(p+1, p+N));
    
    cout << ans << endl;
    
    return 0;
}