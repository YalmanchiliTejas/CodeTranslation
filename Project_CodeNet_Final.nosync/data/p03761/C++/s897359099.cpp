#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int main(){
    int N; cin >> N;
    vector<string> s(N);
    for(int i=0; i<N; i++) cin >> s[i];

    string ans = "";
    for(char c='a'; c<='z'; c++){
        int cnt = 100;
        for(int i=0; i<N; i++){
            int tmp = 0;
            for(int j=0; j<s[i].size(); j++) if(s[i][j] == c) tmp++;
            cnt = min(cnt, tmp);
        }
        for(int i=0; i<cnt; i++) ans += c;
    }

    cout << ans << endl;

}