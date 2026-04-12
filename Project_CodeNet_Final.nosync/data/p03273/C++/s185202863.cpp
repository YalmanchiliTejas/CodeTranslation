#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<string> ans;
    rep(i,h){
        bool removed = true;
        rep(j,w){
            if(s[i][j] == '#') removed = false;
        }
        if(removed) continue;
        //cout << s[i] << endl;
        ans.push_back(s[i]);
    }
    rep(j,w){
        bool removed = true;
        rep(i,ans.size()){
            if(ans[i][j] == '#')removed = false;
        }
        if(removed) {
            rep(i, ans.size()){
                ans[i][j] = '*';
            }
        }
    }
    rep(i,ans.size()){
        rep(j,w){
            if(ans[i][j] == '*')continue;
            cout << ans[i][j];
        }
        cout << endl;
    }
}