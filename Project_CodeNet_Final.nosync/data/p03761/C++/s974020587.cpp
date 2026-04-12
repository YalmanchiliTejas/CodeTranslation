#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<vector<int> > cnt(n, vector<int>(26,0));

    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        int len = s.length();
        // 各文字列の各アルファベット数をカウント
        for(int j=0; j<len; j++){
            cnt[i][s[j]-'a']++;
        }
    }

    for(int i=0; i<26; i++){
        int flg=51;
        for(int j=0; j<n; j++){
           flg = min(flg, cnt[j][i]); 
        }
        if(flg == 51){  // 各アルファベットの共通数を選択
            continue;
        }
        for(int k=0; k<flg; k++){
            cout<<(char)(i+'a');
        }
    }
    cout << endl;

    return 0;
}