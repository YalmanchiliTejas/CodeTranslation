#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
using P = pair<int, int>;


// ------------------------

void solve() {
    string S;
    cin >> S;
    int cntA = 0;
    int cntB = 0;
    if(S[0] == 'A'){
        ++cntA; 
        }else{
             ++cntB;
        }
    if(S[1] == 'A'){
        ++cntA; 
        }else{
             ++cntB;
        }
    if(S[2] == 'A'){
        ++cntA; 
        }else{
             ++cntB;
        }


    if(cntA == 3 or cntB == 3){
        cout << "No" << "\n";
        return;
    }

    cout << "Yes" << "\n";
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}