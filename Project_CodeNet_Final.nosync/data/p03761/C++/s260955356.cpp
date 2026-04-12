    #include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    const string al = "abcdefghijklmnopqrstuvwxyz";
    int n;
    cin >> n;
    string s[n];
    rep(i, n) cin >> s[i];
    int num[n][26];
    rep(i, n)rep(j, 26) num[i][j] = 0;
    rep(i, n){
        rep(j, s[i].size()){
            num[i][s[i][j]-'a']++;
        }
    }
    int ans[26];
    rep(j, 26){
        int mn = 100000;
        rep(i, n){
            mn = min(num[i][j], mn);
        }
        ans[j] = mn;
    }
    rep(i, 26){
        rep(j, ans[i]){
            cout << al[i];
        }
    }cout << endl;
}
