#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main(){
    int n; string str; int s[50] = {0}; int s2[50];
    for (int i = 0; i < 50; i++)
        s2[i] = 50;
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> str;
        for (int j = 0; j < str.size(); j++)
            s[str[j] - 'a'] += 1;
        for (int j = 0; j < 50; j++){
            s2[j] = min(s2[j], s[j]);
            s[j] = 0;
            }
    }
    for (int i = 0; i < 50; i++){
        for(int j = 0; j < s2[i]; j++)
            cout << char(i + int('a'));
    }
    cout << '\n';
    return 0;
}