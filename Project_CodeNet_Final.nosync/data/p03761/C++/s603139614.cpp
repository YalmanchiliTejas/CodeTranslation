#include <bits/stdc++.h>
using namespace std;
int a[50][26];
string s;

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<s.size();j++){
            a[i][s[j]-'a']++;
        }
    }
    s.clear();
    int com;
    for(int i=0;i<26;i++){
        com=1e9;
        for(int j=0;j<n;j++){
            com=min(com,a[j][i]);
        }
        string ss="";
        for(int j=0;j<com;j++){
            ss.push_back(char(i+'a'));
        }
        s+=ss;
    }
    sort(s.begin(),s.end());
    cout << s << endl;
    return 0;
}