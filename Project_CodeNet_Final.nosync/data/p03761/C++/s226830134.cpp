#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int INF = 1001001001;

int main() {
    int N; cin >> N;
    vector<int> ans(26, INF);
    rep(i, N){
        string S; cin >> S;
        int ss = S.size();
        vector<int> now(26, 0);
        rep(j, ss){
            int a = S[j] - 'a';
            now[a]++;
        }
        rep(j, 26){
            ans[j] = min(ans[j], now[j]);
        }
    }

    rep(i, 26){
        int x = ans[i];
        rep(j, x){
            char c = 'a' + i;
            cout << c;
        }
    }

    cout << endl;

    return 0;
}