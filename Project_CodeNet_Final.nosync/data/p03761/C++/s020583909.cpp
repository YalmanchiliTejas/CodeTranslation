#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

int main() {
    int n;
    cin >> n;
    string ans;
    string s[51];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    //a~zのcharループで文字列判定を行う
    for(char c = 'a'; c <= 'z'; c++){
        int small = 1000;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < s[i].size(); j++){
                if(s[i][j] == c) cnt++;
            }
            small = min(small, cnt);
        }
        for(int i = 0; i < small; i++){
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}