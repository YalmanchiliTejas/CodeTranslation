#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int mod = 1e9+7;
 
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cnt(26,vector<int>(n));
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++) cnt[s[j]-'a'][i]++;
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < *min_element(cnt[i].begin(),cnt[i].end()); j++){
            cout << char('a'+i);
        }
    }
    cout << endl;
    return 0;
}