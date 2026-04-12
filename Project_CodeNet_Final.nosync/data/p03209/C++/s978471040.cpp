#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
#define int long long
#define P pair<int,int>

int n,x;
int tot[55],pat[55];

int dfs(int N, int X){
    if(N == 0) {
        if(X <= 0) return 0;
        else return 1;
    }
    else if(X <= tot[N-1] + 1) return dfs(N-1,X-1);
    else return pat[N-1] + 1 + dfs(N-1,X - tot[N-1] - 2);
}

signed main() {
    cin >> n >> x;

    tot[0] = 1;
    pat[0] = 1;
    for(int i = 1; i <= n; i++){
        tot[i] = tot[i-1] * 2 + 3;
        pat[i] = pat[i-1] * 2 + 1;
    }
    cout << dfs(n,x) << endl;
}
