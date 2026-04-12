#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, k, n) for(int i = k; i < (int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<string> s;
    vector<vector<int>> m;
    m.resize(n);
    s.resize(n);
    rep(i,n){
        cin >> s[i];
        m[i].resize(26,0);
        rep(j,s[i].length()){
            m[i][s[i][j]-'a']++;
        }
    }
    vector<int> ans;
    ans.resize(26,100);
    rep(i,26){
        rep(j,n)
        ans[i]=min(ans[i],m[j][i]);
    }

    rep(i,26){
        rep(j,ans[i])printf("%c", 'a'+i);
    }
    cout << endl;
    return 0;
}