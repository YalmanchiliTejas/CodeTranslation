#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    char s[n+1];
    int k;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s[i];
    }
    cin >> k;
    for(int i=0;i<strlen(s);i++) {
        if(s[i]!=s[k-1]) {s[i]='*';}
    }
    for(int i=0;i<n;i++) {cout << s[i];}
}
