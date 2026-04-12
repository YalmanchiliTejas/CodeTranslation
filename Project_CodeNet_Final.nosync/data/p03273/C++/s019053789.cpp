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
    int h,w;
    cin >> h >> w;

    vector<string> v(h);
    REP(i,h) cin >> v[i];

    for(int i = h-1;i >= 0; i--) {
        auto it = find(ALL(v[i]),'#');
        if (it == v[i].end()) v.erase(v.begin()+i);
    }
    for(auto i = w-1; i >=0;i--) {
        bool erase = true;
        REP(j,v.size()) {
            if (v[j][i] == '#') {
                erase = false;
                break;
            }
        }
        if (erase) {
            REP(j,v.size()) v[j].erase(v[j].begin()+i);
        }
    }

    REP(i,v.size()) {
        cout << v[i] << endl;
    }

    return 0;
}