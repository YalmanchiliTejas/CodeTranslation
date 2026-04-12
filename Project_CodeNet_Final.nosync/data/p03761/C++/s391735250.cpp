#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int A[n][26] = {};

    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            A[i][(int)s[j] - 'a']++;
        }
    }

    string ans = "";
    for(int i = 0; i < 26; i++){
        int tmp = 1e9;
        for(int j = 0; j < n; j++){
            tmp = min(tmp, A[j][i]);
        }
        for(int j = 0; j < tmp; j++){
            ans += 'a' + i;
        }
    }
    cout << ans << endl;

    return 0;
}