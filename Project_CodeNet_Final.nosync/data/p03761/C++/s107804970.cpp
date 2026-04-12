#include<bits/stdc++.h>
using namespace std;


int cnt[50][26];

int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string S;
        cin >> S;
        for(int j=0;j<S.length();j++){
            cnt[i][S[j]-'a'] ++;
        }
    }

    for(int i=0;i<26;i++){
        int m = 100000000;
        for(int j=0;j<n;j++){
            m = min(m, cnt[j][i]);
        }

        for(int k=0;k<m;k++) cout << (char)(i+'a');
    }
    cout << endl;
    return 0;
}