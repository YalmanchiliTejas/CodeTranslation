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

bool getans(char c, bool prev, bool now) {
    bool ret;
    if (now) {   // W
        if (c == 'o') {
            ret = !prev;
        } else {    // x
            ret = prev;
        }
    } else {    // S
        if (c == 'o') {
            ret = prev;
        } else {    // x
            ret = !prev;
        }
    }
    return ret;
}

bool valid(char c,bool prev,bool now, bool next) {
    bool ret;
    if (now) { // W
        if (c == 'o') {
            ret = prev != next;
        } else {
            ret =  prev == next;
        }
    } else {
        if (c == 'o') {
            ret = prev == next;
        } else {
            ret = prev != next;
        }
    }
    return ret;
}

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
            ans[j+1] = getans(s[j],ans[j-1],ans[j]);
        }

        if (!valid(s[l-1],ans[l-2],ans[l-1],ans[0])) continue;
        if (!valid(s[0],ans[l-1],ans[0],ans[1])) continue;

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