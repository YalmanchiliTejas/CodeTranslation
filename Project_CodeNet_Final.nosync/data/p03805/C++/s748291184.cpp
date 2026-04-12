#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

bool path[10][10];
ll n;
ll c = 0;

void dfs(ll s, bool* check){
    if(check[s] == true){
        return;
    }

    check[s] = true;

    bool ch = true;
    rep(i, n){
        if(check[i] == false) ch = false;
    }
    if(ch == true){
        c++;
    }

    rep(i, n){
        if(path[s][i]) dfs(i, check);
    }

    check[s] = false;
    return;
}

int main(void){
    ll m;
    cin >> n >> m;
    rep(i, m){
        ll tmp_a, tmp_b;
        cin >> tmp_a >> tmp_b;
        tmp_a--;
        tmp_b--;
        path[tmp_a][tmp_b] = true;
        path[tmp_b][tmp_a] = true;
    }

    bool check[n];
    rep(i, n) check[i] = false;

    dfs(0, check);

    cout << c << endl;
    return 0;
}
