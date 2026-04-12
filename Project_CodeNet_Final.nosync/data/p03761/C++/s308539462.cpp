#include <bits/stdc++.h>
using namespace std;

int freq[50][300];

int main(){

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(char c : s)
            freq[i][c]++;
    }
    string res = "";
    for(int j = 'a'; j <= 'z'; j++){
        int cnt = 1e9;
        for(int i = 0; i < n; i++)
            cnt = min(cnt, freq[i][j]);
        for(int i = 0; i < cnt; i++)
            res += char(j);
    }
    cout << res << endl;
	return 0;
}