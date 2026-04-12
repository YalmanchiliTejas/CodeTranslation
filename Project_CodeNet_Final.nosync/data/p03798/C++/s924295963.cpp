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

int main(void)
{
    IOS
    constexpr int N = 1e5;
    int n; cin >> n;
    string s; cin >> s;
    int l = s.size();

    REP(i,4) {
        bitset<N+10> ans(i);

        FOR(j,1,l-1){
            if (ans[j]) {   // W
                if (s[j] == 'o') {
                    ans[j+1] = ~ans[j-1];
                } else {    // x
                    ans[j+1] = ans[j-1];
                }
            } else {    // S
                if (s[j] == 'o') {
                    ans[j+1] = ans[j-1];
                } else {    // x
                    ans[j+1] = ~ans[j-1];
                }
            }
        }

        if (ans[l-1]) { // W
            if (s[l-1] == 'o') {
                if (ans[0] == ans[l-2]) continue;
            } else {
                if (ans[0] != ans[l-2]) continue;
            }
        } else {
            if (s[l-1] == 'o') {
                if (ans[0] != ans[l-2]) continue;
            } else {
                if (ans[0] == ans[l-2]) continue;
            }
        }
        if (ans[0]) { // W
            if (s[0] == 'o') {
                if (ans[1] == ans[l-1]) continue;
            } else {
                if (ans[1] != ans[l-1]) continue;
            }
        } else {
            if (s[0] == 'o') {
                if (ans[1] != ans[l-1]) continue;
            } else {
                if (ans[1] == ans[l-1]) continue;
            }
        }

        string astr = "";
        REP(j,l){
            astr += ans[j] ? "W" : "S";
        }
        cout << astr << endl;
        return 0;
    }
    cout << "-1" << endl;


    return 0;
}