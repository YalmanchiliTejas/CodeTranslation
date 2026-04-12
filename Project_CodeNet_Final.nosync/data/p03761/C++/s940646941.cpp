#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> cnt(26);
    vector<string> s(n);
    for(int i = 0;i < n;i ++){
        vector<int> cnts(26);
        cin >> s[i];
        for(int j = 0;j < s[i].size();j ++){
            cnts[s[i][j]-'a'] ++;
        }
        for(int j = 0;j < 26;j ++){
            if(i==0) cnt[j] = cnts[j];
            else cnt[j] = min(cnt[j],cnts[j]);
        }
    }
    string ans = "";
    for(int i = 0;i < 26;i ++){
        for(int j = 0;j < cnt[i];j ++){
            ans += i+'a';
        }
    }
    cout << ans << endl;
    return 0;
}