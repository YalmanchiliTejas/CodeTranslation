#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
#include <bits/stdc++.h>
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    map<char, int> m;
    for(char c = 'a'; c <= 'z'; c++){
        m[c] = 50;
    }

    for (int i = 0; i < n; i++){
        for (char c = 'a'; c <= 'z'; c++){
            int num = count(s[i].begin() , s[i].end() , c);
            m[c] = min(m[c] , num);
        }
    }
    string ans;
    for (char c = 'a'; c <= 'z'; c++){
        string t(m[c] , c);
        ans += t;
    }
    cout << ans << endl;
}
