#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s[51];
int alph[50][26] = {};
int alph_cnt[26] = {};

int main()
{   int N;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> s[i];

    for(int i=0; i<N; i++){
        int j = 0;
        while(s[i][j] != '\0'){
            int k = s[i][j] - 'a';
            alph[i][k]++;
            j++;
        }
    }

    for(int i=0; i<26 ;i++){
        int min_cnt = 50;
        for(int j=0; j<N;j++){
            min_cnt = min(min_cnt, alph[j][i]);
        }
        alph_cnt[i] = min_cnt;
    }

    for(int i=0; i<26; i++)
        while(alph_cnt[i]){
            char c = 'a' + i;
            cout << c;
            alph_cnt[i]--;
        }
    cout << '\n';
}
