#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define rep1(i, n) for(int i = 1; i <= (int) n; i++)
#define all(v) v.begin(),v.end()

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> Min(26,50), cnt(26);
    rep(i,n) {
        cin >> s[i];
        rep(j,s[i].size()) {
            cnt[s[i][j]-(int)'a']++;
        }
        rep(j,26) {
            Min[j] = min(Min[j], cnt[j]);
            cnt[j] = 0;
        }
    }
    rep(i,26) {
        rep(j,Min[i]) {
            cout << (char)('a'+i);
        }
    }
    cout << endl;
    return 0;
}