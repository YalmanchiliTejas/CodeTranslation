#include <bits/stdc++.h>
using namespace std;
void OnestrokePath(int n,vector<vector<int>> &ABC,vector<bool> &ok,int &ans) {
    bool ok2 = true;
    for(int i = 0; i < ok.size(); i++) {
        if(ok[i] == false && i != n) {
            ok2 = false;
        }
    }
    if(ok2) {
        ans++;
        return;
    }
    ok[n] = true;
    for(int i = 0; i < ABC[n].size(); i++) {
        if(ok[ABC[n][i]] == true) {
            continue;
        }
        OnestrokePath(ABC[n][i],ABC,ok,ans);
    }
    ok[n] = false;
    return;
}
int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>>ABC(N);
    vector<bool>ok(N,false);
    for(int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        ABC[a].push_back(b);
        ABC[b].push_back(a);
    }
    int ans = 0;
    OnestrokePath(0,ABC,ok,ans);
    cout << ans << endl;
}
