#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
    int N;
    cin >> N;
    vector<map<char,int>> chars(N); 
    string alp{"abcdefghijklmnopqrstuvwxyz"};
    rep(i, N) for(auto& c : alp) chars[i][c] = 0;
    rep(i, N){
        string S; cin >> S;
        for(auto& c : S) chars[i][c]++;
    }

    string ans = "";
    for(auto& c : alp){
        int MIN = 1e9;
        rep(i, N) MIN = min(MIN, chars[i][c]);
        string tmp(MIN, c);
        ans += tmp;
    }
    cout << ans << endl;
}

