#include <bits/stdc++.h>
using namespace std;

int  s[50][26];
int ans[26];

int main(){
    int n;
    cin >> n;

    for(int i=0; i < n; i++){
        string temp;
        cin >> temp;
        for(int j=0; j < (int)temp.size(); j++){
            s[i][temp[j] - 'a'] += 1;
        }
    }

/*
    for(int i=0; i < n; i++){
        int tmp = 99999;
        for(int j=0; j < n; j++){
            tmp = min(tmp, s[j][i]);
        }
        ans[i] = tmp;
    }



    for(int i=0; i < 26; i++){
        for(int j=0; j < ans[i]; j++){
            char alph = i + 'a';
            cout << alph;
        }
    }
    cout << endl;
*/
    for(int i=0; i < 26; i++){
        int mi = s[0][i];
        for(int j=0; j < n; j++){
            mi = min(mi, s[j][i]);
        }
        for(int k=0; k < mi; k++){
            char alph = i + 'a';
            cout << alph;
        }
    }
    cout << endl;

    return 0;
}
