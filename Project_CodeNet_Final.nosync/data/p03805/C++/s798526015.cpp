#include<bits/stdc++.h>
/*
g++ -std=c++11 -Wall -g -fsanitize=undefined -D_GLIBCXX_DEBUG abc/abc054/c.cpp
*/
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SZ(x) ((int)(x).size())
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);//おまじないでcin, cout早くする
    int N, M;
    cin >> N >> M;
    vector<vector<int>> m(N, vector<int>(N, 0));
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        m[a][b] = 1;
        m[b][a] = 1;
    }

    ll ans = 0;
    vector<int> v(N);
    rep(i, N){
        v[i] = i;
    }

    do{
        if(v[0] != 0) break;
        int flag = 0;
        rep(i, N - 1){
            if(m[v[i]][v[i + 1]] == 0) flag = 1;
        }
        if(flag) continue;
        else ans++;
    }while(next_permutation(v.begin(), v.end()));

    cout << ans << "\n";
    return 0;
}