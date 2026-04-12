#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main(){
    int i, j, n;
    int letter[26];
    string s;
    cin >> n;
    for(i=0; i<26; i++){
        letter[i] = MOD;
    }
    for(i=0; i<n; i++){
        cin >> s;
        int tem[26] = {};
        for(j=0; j<s.length(); j++){
            tem[s[j]-'a']++;
        }
        for(j=0; j<26; j++){
            letter[j] = min(letter[j], tem[j]);
        }
    }
    for(i=0; i<26; i++){
        if(letter[i] == MOD){
            continue;
        }
        for(j=0; j<letter[i]; j++){
            cout << (char)('a'+i);
        }
    }
    return 0;
}