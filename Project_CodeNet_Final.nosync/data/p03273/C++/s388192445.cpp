#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n ; i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x) // decltypeで型取得、引数があればva_argsのところに入れる
using namespace std;
typedef long long ll; // long longをllでかけるようにした
const int INF = 1e9;

int main(void){
    int gyou, retsu; cin >> gyou >> retsu;
    vector<string> A(gyou);
    REP(i, gyou) cin >> A[i];
    vector<bool> row(gyou, false);
    vector<bool> col(retsu, false);
    REP(i, gyou){
        REP(j, retsu){
            if(A[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    REP(i, gyou){
        if(row[i]){
            REP(j, retsu){
                if(col[j]) cout << A[i][j];
            }
            cout << endl;
        }
    }

}