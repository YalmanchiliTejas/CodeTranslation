#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    int H,W; cin >> H >> W;
    vector<vector<char>> A(H,vector<char>(W));

    set<int> yoko;
    REP(i,H){
        bool ok = true;
        string S;
        cin >> S;
        REP(j,W){
            A[i][j] = S[j];
            if(A[i][j] == '#') ok = false;
        }
        if(ok){
            yoko.insert(i);
        }
    }
    set<int> tate;
    REP(j,W){
        bool ok = true;
        REP(i,H){
            if(A[i][j] == '#') ok = false;
        }
        if(ok){
            tate.insert(j);
        }
    }

    REP(i,H){
        REP(j,W){
            if(yoko.find(i)==yoko.end() && tate.find(j)==tate.end()){
                cout << A[i][j];
            }
        }
        if(yoko.find(i)==yoko.end()){
            cout << endl;
        }
    }

    return 0;
}