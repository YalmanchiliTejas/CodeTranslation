#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPm(i,n) for(int i=(n)-1;i>=0;i--)
#define REP1(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
int main(){
    int H,W;
    int c = 0;
    cin >> H >> W;
    REP(i,H){
        string A;
        cin >> A;
        REP(j,W){
            if(A[j] == '#') c++;
        }
    }
    if(H+W-1 == c) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}
