#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int d[26];
    for(int i = 0; i < 26; i++) d[i] = 1000000;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int a[26] = {};
        for(int j = 0; j < s.size(); j++){
            a[s[j] - 'a']++;
        }
        for(int j = 0; j < 26; j++){
            d[j] = min(d[j], a[j]);
        }
    }    
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < d[i]; j++) putchar('a'+i);
    }

    return 0;
}