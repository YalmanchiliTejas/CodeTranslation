#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> tmp;
    vector<vector<int>> bra(n, tmp);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        bra[a-1].push_back(b-1);
        bra[b-1].push_back(a-1);
    }
    int res=0;
    queue<P> q;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        P now = q.front();
        q.pop();
        if((now.second>>now.first)%2==0){
            now.second += 1<<now.first;
            if (now.second == (1 << n) - 1) {
              res++;
            }
            int len = bra[now.first].size();
            rep(i, len){
                q.push(make_pair(bra[now.first][i], now.second));
            }
        }
    }
    cout << res << endl;
    return 0;
}