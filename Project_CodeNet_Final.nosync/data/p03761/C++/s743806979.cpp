#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

int main(void)
{
    IOS
    int n; cin >> n;
    map<char,int> m;
    REP(i,n) {
        string s; cin >> s;
        map<char,int> m2;
        for(auto c:s) {
            m2[c]++;
        }
        if (i == 0) m = m2;
        else {
            for(auto c:m) {
                m[c.first] = min(m[c.first],m2[c.first]);
            }
        }
    }
    string ans = "";
    for(auto c: m) {
        string s(c.second,c.first);
        ans += s;
    }

    cout << ans << endl;


    return 0;
}