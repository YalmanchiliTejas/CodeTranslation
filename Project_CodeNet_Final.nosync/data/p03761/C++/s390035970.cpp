#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n,vector<int>(26));
    rep(i,n) {
        string s;
        cin >> s;
        for(char x : s) {
            int temp = x-'a';
            m[i][temp]++;
        }
    }
    string ans = "";
    rep(i,26){
        int c = 100;
        rep(j,n){
            c = min(c, m[j][i]);
        }
        if(c!=0){
            rep(k,c) ans.push_back('a'+i);
        }
    }
    cout << ans << endl;
    return 0;
}