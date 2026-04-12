#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int  N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int>cnt(N,INF);
    for(int i = N-1; i >= 0; i--) {
        auto it = upper_bound(cnt.begin(),cnt.end(),A[i]);
        cnt[it-cnt.begin()] = A[i];
    }
    cout << lower_bound(cnt.begin(),cnt.end(),INF)-cnt.begin() << endl;
}