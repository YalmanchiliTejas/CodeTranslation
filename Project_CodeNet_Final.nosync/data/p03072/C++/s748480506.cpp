#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> P;

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, pre = -1, ans = 0; cin >> N;
    for(int i=0;i<N;i++){
        int h; cin >> h;
        if(h>=pre) ans++;
        pre = max(pre, h);
    }
    cout << ans << endl;
    return 0;
}