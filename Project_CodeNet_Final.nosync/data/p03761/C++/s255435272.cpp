#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, ll, ll> T;

int n;
vector<vector<int>> alpha(51, vector<int>(26, 0));

int main(void){
    
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        for(int j = 0; j < s.size(); ++j) ++alpha[i][s[j] - 'a'];
    }
    
    vector<int> v(26, INT_MAX);
    for(int i = 0; i < n; ++i) for(int j = 0; j < 26; ++j) v[j] = min(v[j], alpha[i][j]);
    
    string s;
    for(int i = 0; i < 26; ++i) for(int j = 0; j < v[i]; ++j) s.push_back('a' + i);
    cout << s << endl;
    
    return 0;
}