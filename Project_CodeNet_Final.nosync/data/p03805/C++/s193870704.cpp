#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> p(n, vector<bool>(n,false));
    rep(i,m){
        int a,b;
        cin >> a >> b;
        p[a-1][b-1] = true;
        p[b-1][a-1] = true;
    }
    vector<int> one_case;
    rep(i,n-1) one_case.push_back(i+1); // 1~(n-1)
    int cnt = 0;
    do {
        bool ok = true;
        rep(i, n-1){
            int now_node = one_case[i];
            int next_node = one_case[i+1];
            if(!p[now_node][next_node]) {ok=false;break;}
        }
        if(ok) cnt++;
    } while(next_permutation(one_case.begin(), one_case.end()));
    cout << cnt << endl;
}