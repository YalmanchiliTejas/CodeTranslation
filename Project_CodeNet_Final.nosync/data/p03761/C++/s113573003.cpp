#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s[100];
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    string ans = "";

    for(char c='a'; c<='z'; c++){
        int minCharCount = 100;
        for(int i=0; i<n; i++){
            int tmpCharCount = 0;
            for(int j=0; j<s[i].size(); j++){
                if(s[i][j] == c) tmpCharCount++;
            }
            minCharCount = min(minCharCount, tmpCharCount);
        }
        for(int k=0; k<minCharCount; k++){
            ans += c;
        }
    }

    cout << ans << endl;
    return 0;
}