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
    string s; cin >> s;
    for(int i=0; i<s.size()-1; i++){
        if(s[i] == 'A' && s[i+1] == 'C'){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}