#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int alph[26];
    for(int i = 0 ; i < 26; i++){
        alph[i] = 10000;
    }
    for(int i = 0; i < n; i++){
        int cnt[26] = {};
        for(int j = 0; j < s[i].size(); j++){
            for(char k = 'a'; k <= 'z'; k++){
                if(s[i][j] == k){
                    cnt[(int)(k-'a')]++;
                }
            }
        }
        for(int j = 0; j < 26; j++){
            alph[j] = min(alph[j],cnt[j]);
        }
    
    }
    string ans = "";
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < alph[i]; j++){
            ans += char(i+'a');
        }
    }
    cout << ans << endl;

    return 0;
}