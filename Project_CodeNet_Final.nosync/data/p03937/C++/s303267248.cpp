#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h)cin >> s[i];
    int cnt = 0;
    rep(i, h)rep(j, w)if(s[i][j] == '#')cnt++;
    if(cnt == h+w-1)cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    
}