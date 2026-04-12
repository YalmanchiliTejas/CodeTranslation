#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    int rmin = 1e9,rmax = 0,bmin = 1e9,bmax = 0,cnt = 1;
    priority_queue<P,vector<P>,greater<P>> que;
    for (int i = 0;i < n;++i) {
        int x,y;
        cin >> x >> y;
        if (x > y) swap(x,y);
        rmin = min(rmin,y);
        bmin = min(bmin,x);
        bmax = max(bmax,x);
        if (rmax == y) cnt++;
        else if (rmax < y) cnt = 1;
        rmax = max(rmax,y);
        que.push(P(x,y));
    }
    ll ans = (ll)(rmax-rmin)*(bmax-bmin);
    while (1) {
        P t = que.top();
        que.pop();
        if (t.first >= t.second) break;
        if (t.second == rmax) cnt--;
        if (cnt == 0) break;
        swap(t.first,t.second);
        que.push(t);
        bmax = max(bmax,t.first);
        rmin = min(rmin,t.second);
        bmin = que.top().first;
        ans = min(ans,(ll)(rmax-rmin)*(bmax-bmin));
    }
    cout << ans << endl;
    return 0;
}