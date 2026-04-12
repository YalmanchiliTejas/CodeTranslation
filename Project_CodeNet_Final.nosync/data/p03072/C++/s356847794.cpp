#include <iostream>
#include <algorithm>
#include <vector>
#define REP(i, n) for(int i=0;i<n;++i)

typedef long long ll;
using namespace std;
int main(){
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h = {};
    REP(i, n){ int x; cin >> x; h.push_back(x); }
    int ans = 0;
    REP(i, n){
        bool flg = true;
        REP(j, i){
            if(h[j]>h[i])flg = false;
        }
        if(flg)++ans;
    }
    cout << ans << "\n";
    return 0;
}