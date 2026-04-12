#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n,m;
vector<vector<int>> edge(10);

int main(){
    cin >> n >> m;
    rep(i,m){
        int a,b; cin >> a >> b;
        --a;--b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> root;
    rep(i,n) root.push_back(i);
    int cnt = 0;
    do{
        bool flag = true;
        rep(i,n-1){
            vector<int> s = edge[root[i]];
            if(find(ALL(s),root[i+1]) == s.end()) flag = false;
            if(root[0] != 0) flag = false;
        }
        if(flag) cnt++;
    }while(next_permutation(ALL(root)));
    cout << cnt << endl;
}