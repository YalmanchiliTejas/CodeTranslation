#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//long longのシフト演算には気をつけよう

int main(){
    int N; cin >> N;
    vector<string> s(N);
    string ans = "";
    for(int i=0; i<N; i++) cin >> s[i];

    for(char c='a'; c<='z'; c++){
        int v = 100;
        for(int i=0; i<N; i++){
            v = min(v, (int)count(s[i].begin(), s[i].end(), c));
        }

        for(int i=0; i<v; i++) ans += c;
    }

    cout << ans << endl;
}