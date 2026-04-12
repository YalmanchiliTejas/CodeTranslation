#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[100005] = {};
signed main() {
    int N;
    string S;
    int K;
    cin >> N >> S >> K;
    for(int i = 0; i < N; i++) {
        if(S[i] != S[K-1]) {
            cout << '*';
        }
        else {
            cout << S[i];
        }
    }
    cout << endl;
}
