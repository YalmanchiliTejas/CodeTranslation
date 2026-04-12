#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define REP(i, n) for(int i=0; i<n; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 1e9+7;

struct edge{
    int to;
    int cost;
};
using graph = vector<vector<edge>>;

int main(){
    str s; cin >> s;
    bool aorbonly = false;
    if(s[0] == 'A' && s[1] == 'A' && s[2] == 'A') aorbonly = true;
    if(s[0] == 'B' && s[1] == 'B' && s[2] == 'B') aorbonly = true;
    if(aorbonly) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}