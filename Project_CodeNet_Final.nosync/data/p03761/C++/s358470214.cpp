
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> S(n);
    for(int i = 0; i < n; i++){
        cin >> S[i];
    }

    vector<int> cnt(26, 50);
    for(int i = 0; i < n; i++){
        vector<int> cnt_S(26);
        for(int j = 0; j < S[i].size(); j++){
            cnt_S[S[i][j]-'a']++;
        }
        for(int j = 0;j < 26; j++){
            cnt[j] = min(cnt[j], cnt_S[j]);
        }
    }

    string ans = "";
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < cnt[i]; j++){
            ans += i+'a';
        }
    }
    cout << ans << endl;
    
    
    return 0;
}