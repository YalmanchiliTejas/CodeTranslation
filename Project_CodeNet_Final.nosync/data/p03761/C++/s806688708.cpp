#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    vector<unordered_map<int,int>> MP(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < S[i].size(); j++){
            MP[i][S[i][j]]++;
        }
    }
    int cnt[26] = {0};
    memset(cnt, 50, sizeof(cnt));
    for(char c = 'a' ; c <= 'z' ; c++){
        for(int i = 0; i < N; i++){
            cnt[c - 'a'] = min(MP[i][c], cnt[c-'a']);
        }
    }
    for(int i = 0; i < 26; i++){
        while(cnt[i] > 0){
            cout << (char)('a' + i);
            cnt[i]--;
        }
    }
    cout << endl;
}