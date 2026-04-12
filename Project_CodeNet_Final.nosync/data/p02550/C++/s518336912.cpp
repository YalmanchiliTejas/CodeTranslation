#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,X,M;
    cin >> N >> X >> M;
    vector<int>used(100005);
    int old = X,j = 1;
    used[X] = true;
    while (true) {
        old = old*old%M;
        if(used[old]) {
            break;
        }
        used[old] = true;
        j++;
    }
    int sum = X;
    int now = X;
    old = X;
    for(int i = 2; i <= min(N,j); i++) {
        sum += old*old%M;
        old = old*old%M;
        now = old;
    }
    if(N <= j) {
        cout << sum << endl;
        return 0;
    }
    vector<int>s(100005);
    int cnt = 1;
    while (true) {
        old = old*old%M;
        s[cnt] = s[cnt-1]+old;
        if(old == now) {
            break;
        }
        cnt++;
    }
    cout << sum+(N-min(N,j))/cnt*s[cnt]+s[(N-min(N,j))%cnt] << endl;
}
