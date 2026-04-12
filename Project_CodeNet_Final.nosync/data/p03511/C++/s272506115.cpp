#include "bits/stdc++.h"
using namespace std;
const int magic = 30000000;
int main(){
    int L;
    string u, v, s, t;
    cin >> L;
    cin >> u >> v;
    while(s.size() < magic) s += u;
    while(t.size() < magic) t += v;
    if(s > t) swap(u, v);
    int use = 0;
    for(int e = 1; e <= L; e++){
        int take = L; take -= e * u.size();
        if(take < 0) break;
        if(take % v.size() == 0) use = e;
    }
    string ans;
    for(int e = 0; e < use; e++) ans += u;
    while(ans.size() != L) ans += v;
    cout << ans << endl;
    return 0;
}
