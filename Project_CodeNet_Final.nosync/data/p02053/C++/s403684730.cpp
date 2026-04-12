#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    string S[1000];
    for(int i=0; i<H; i++) cin >> S[i];

    vector<pair<int, int>> cand;
    for(int i=0; i<H; i++){
        int l = -1, r = -1;
        for(int j=0; j<W; j++) if(S[i][j] == 'B'){
            if(l == -1) l = j;
            r = j;
        }
        if(l >= 0){
            cand.emplace_back(i, l);
            cand.emplace_back(i, r);
        }
    }

    int ans = 0;
    for(auto& p : cand) for(auto& q : cand){
        int res = abs(p.first-q.first) + abs(p.second-q.second);
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}

