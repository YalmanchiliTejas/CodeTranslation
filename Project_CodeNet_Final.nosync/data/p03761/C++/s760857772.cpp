#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int oo = 1e9 + 7;
const int mod = 1e9 + 7, maxn = 100100;
const long double PI = acos(-1);
 
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;

    cin >> n;

    vector<int> alpha(26, 0);

    cin >> s;
    for (int i=0; i<s.size(); i++){
        alpha[s[i] - 'a']++;
    }

    for (int k = 0; k < n-1; k++){
        vector<int> cnt(26, 0);
        cin >> s;
        for (int i=0; i<s.size(); i++){
            cnt[s[i] - 'a']++;
        }

        for (int i=0; i<26; i++){
            alpha[i] = min(alpha[i], cnt[i]);
        }
    }

    string ans;

    for (int i=0; i<26; i++){
        ans.append(alpha[i], char('a' + i));
    }
    cout << ans << endl;
    return 0;
}