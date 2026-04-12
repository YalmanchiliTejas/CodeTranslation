#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    set<int> E[N];
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        E[a].insert(b);
        E[b].insert(a);
    }
    int A[N], ans = 0;
    rep(i, N) A[i] = i;
    do{
        int t = 1;
        rep(i, N - 1){
            if(E[A[i]].find(A[i + 1]) == E[A[i]].end()) t = 0;
        }
        ans += t;
    }while(next_permutation(A + 1, A + N));
    cout << ans << endl;
    return 0;
}