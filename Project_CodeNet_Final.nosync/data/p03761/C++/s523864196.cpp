#include<iostream>
#include<string>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n;
    cin >> n;
    string s[n];
    rep(i, n) cin >> s[i];
    int a[n][26];
    rep(i, n)rep(j, 26) a[i][j] = 0;
    string al = "abcdefghijklmnopqrstuvwxyz";
    rep(i, n)rep(j, s[i].size())rep(k, 26){
        if (s[i][j] == al[k]){
            a[i][k]++;
            continue;
        }
    }
    int ans[26];
    rep(i, 26) ans[i] = 1000000;
    rep(i, n)rep(j, 26){
        ans[j] = min(ans[j], a[i][j]);
    }
    rep(i, 26)rep(j, ans[i]){
        cout << al[i];
    }
    cout << endl;
}