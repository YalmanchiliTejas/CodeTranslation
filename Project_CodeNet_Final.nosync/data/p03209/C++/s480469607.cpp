#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,X;
    cin >> N >> X;
    vector<int>size(N+1);
    vector<int>paty(N+1);
    size[0] = 1;
    paty[0] = 1;
    for(int i = 0; i < N; i++) {
        size[i+1] = size[i]*2+3;
    }
    for(int i = 0; i < N; i++) {
        paty[i+1] = paty[i]*2+1;
    }
    int ans = 0;
    while(X && N) {
        if(X <= 1+size[N-1]) {
            N--;
            X--;
        }
        else {
            ans+=paty[N-1]+1;
            X-=(2+size[N-1]);
            N--;
        }
    }
    if(X) {
        ans++;
    }
    cout << ans << endl;
}
