#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

string s;
vector<int> alp(26, 0);

int main() {
    alp['y'-'a']++;
    alp['u'-'a']++;
    alp['i'-'a']++;
    alp['o'-'a']++;
    alp['p'-'a']++;
    alp['h'-'a']++;
    alp['j'-'a']++;
    alp['k'-'a']++;
    alp['l'-'a']++;
    alp['n'-'a']++;
    alp['m'-'a']++;
    while(1) {
        cin >> s;
        if(s == "#") break;
        int slen = s.length();
        int now = 0;
        int cnt = 0;
        for(int i = 0; i < slen; ++i) {
            if(i == 0) now = alp[s[i]-'a'];
            else {
                int ch = alp[s[i]-'a'];
                if(now != ch) cnt++;
                now = ch;
            }
        }
        cout << cnt << endl;
    }
}
