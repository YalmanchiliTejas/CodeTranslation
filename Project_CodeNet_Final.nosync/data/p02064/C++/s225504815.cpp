#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n,s,t,u;
    cin >> n >> s >> t;
    vector<P> ans;
    cout << "? " << s << " " << t << "\n";
    cout.flush();
    cin >> u;
    ans.push_back(P(0,s));
    ans.push_back(P(u,t));
    for (int i = 1;i < n+1;++i) {
        if (i == s || i == t) continue;
        int x,y;
        cout << "? " << s << " " << i << "\n";
        cout.flush();
        cin >> x;
        cout << "? " << t << " " << i << "\n";
        cout.flush();
        cin >> y;
        if (x+y == u) ans.push_back(P(x,i));
    }
    sort(ans.begin(),ans.end());
    int m = ans.size();
    cout << "! ";
    for (int i = 0;i < m;++i) cout << ans[i].second << " \n"[i == m-1];
    cout << endl;
    cout.flush();
    return 0;
}
