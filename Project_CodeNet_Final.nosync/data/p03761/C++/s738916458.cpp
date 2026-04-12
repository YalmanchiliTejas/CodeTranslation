#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    map<char,int> mp[n];
    vector<int> f(26,mod);
    string ans;
    
    
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < s[i].size(); j++){
            mp[i][s[i][j]]++;
        }
    }   
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < n; j++){
            if(mp[j]['a'+i] < f[i]) f[i] = mp[j]['a'+i];
        }
        for(int j = 0; j < f[i]; j++){
            ans += 'a'+i;
        }
    } 
    cout << ans << endl;
}