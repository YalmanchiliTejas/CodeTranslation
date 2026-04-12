#include <bits/stdc++.h>
#define int long
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define IOS cin.tie(0); ios::sync_with_stdio(false)
const int INF = 1e9;
using namespace std;

main() {
    string S; cin >> S;
    bool can =false;
    rep(i,S.size()-1){
        if(S[i]=='A' && S[i+1]=='C')
        can = true;
    }
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
}