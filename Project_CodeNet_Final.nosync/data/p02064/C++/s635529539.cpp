#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int question(int u, int v){
    cout << "? " << u << " " << v << endl;
    int res;
    cin >> res;
    return res;
}

int main(){
    int n, s, t, d, g[2][305];
    cin >> n >> s >> t;

    d = question(s, t);
    for(int i=1;i<=n;i++){
        g[0][i] = question(s, i);
    }
    for(int i=1;i<=n;i++){
        g[1][i] = question(t, i);
    }
    vector<P> ls;
    for(int i=1;i<=n;i++){
        if(g[0][i]+g[1][i] == d)ls.push_back({g[0][i], i});
    }
    sort(ls.begin(), ls.end());
    int now = s;
    vector<int> ans;
    ans.push_back(s);
    for(int i=1;i<int(ls.size());i++){
        int to = ls[i].second;
        int tmp = question(now, to);
        if(g[0][to]-g[0][now] == tmp){
            ans.push_back(to);
            now = to;
        }
    }
    cout << "!";
    for(auto x : ans){
        cout << " " << x;
    }
    cout << endl;
    return 0;
}

