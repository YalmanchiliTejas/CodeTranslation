#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define rep(i, n) for(int i = 0; i < (n); i++)

int n;
int cnt[50][30];
string S[50];
char res[51];
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> S[i];
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < S[i].length(); j++) {
            cnt[i][S[i][j]-'a']++;
        }
    }
    int index = 0;
    for (int i = 0; i < 26; i++) {
        int c = cnt[0][i];
        for (int k = 1; k < n; k++) {
            c=min(c,cnt[k][i]);
        }
        for (int k = index; k < index+c; k++) {
            res[k] = 'a' + i;
        }
        index += c;
    }
    cout << res << endl;
 
    
}