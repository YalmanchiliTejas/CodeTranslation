#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    string ans;
    for(int i = 0;i<n;i++)cin >> s[i];
    for(int c = 'a';c <= 'z';c++){
        int small = 100;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j < (int)s.at(i).size();j++){
                if(c == s.at(i).at(j))cnt++;
            }
            small = min(small,cnt);//出てくる単語の最小値的なやつか
        }
        for(int i = 0;i<small;i++){
            ans += c;//a , b , c.....の場合で全部計測してる
        }
    }
    cout << ans << endl;
    return 0;
}