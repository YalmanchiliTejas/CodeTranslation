#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[30] = {INT_MAX};
    for(int j = 0; j <= 'z'-'a'; j++){
        a[j] = INT_MAX;
    }
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int str[30]={0}, len = s.length();
        for(int j = 0; j < len; j++) str[s[j] - 'a']++;
        for(int j = 0; j <= 'z'-'a'; j++){
            a[j] = min(a[j], str[j]);
        }
    }
    for(int j = 0; j <= 'z'-'a'; j++){
        for(int i = 0; i < a[j]; i++) cout << (char)('a'+j);
    }
    cout << endl;
}