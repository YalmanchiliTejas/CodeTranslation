#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

int main(){
    int N; cin >> N;
    string s; cin >> s;
    int k; cin >> k;

    char c = s[k-1];
    for(int i=0; i<s.size(); i++){
        if(s[i] != c) s[i] = '*';
    }

    cout << s << endl;
}