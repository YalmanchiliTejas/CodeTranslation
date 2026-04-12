#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
int main(){
    int n;
    cin >> n;
    map<char, int> mp;
    rep(i, n) {
        string s;
        cin >> s;
        map<char, int> tmp;
        if (i == 0) {
            rep(i, s.size()) {
                mp[s[i]]++;
            }
            continue;
        }
        rep(i, s.size()) {
            tmp[s[i]]++;
        }
        for (auto p: mp) {
            mp[p.first] = min(p.second, tmp[p.first]);
        }
    }
    for (auto p: mp) {
        rep(i, p.second) {
            cout << p.first;
        }
    }
    cout << endl;
    return 0;
}