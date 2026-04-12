#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    string S; cin >> S;
    S += S;
    vector<string> T{"SS", "SW", "WS", "WW"};
    FOR(i,1,N){
        REP(n,4){
            if(T[n][i]=='S' && S[i]=='o') T[n] += T[n][i-1];
            else if(T[n][i]=='S' && S[i]=='x') T[n] += (T[n][i-1]=='S'?'W':'S');
            else if(T[n][i]=='W' && S[i]=='o') T[n] += (T[n][i-1]=='S'?'W':'S');
            else if(T[n][i]=='W' && S[i]=='x') T[n] += T[n][i-1];
        }
    }

    REP(n,4){
        bool ok = false;
        if(T[n][0] == T[n][N]){
            if(S[0]=='o'){
                if(T[n][0]=='S' && T[n][N-1]==T[n][1]){
                    ok = true;

                }else if(T[n][0]=='W' && T[n][N-1]!=T[n][1]){
                    ok = true;
                }
            }else{
                if(T[n][0]=='S' && T[n][N-1]!=T[n][1]){
                    ok = true;

                }else if(T[n][0]=='W' && T[n][N-1]==T[n][1]){
                    ok = true;
                }
            }
        }
        if(ok){
            REP(i,N) cout << T[n][i];
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}