#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(a) sort(a.begin(),a.end())
using namespace std;
int main(){
// Seiranchan!
    int H,W;
    cin >> H >> W;

    vector<string> A(H);
    REP(i,H) cin >> A[i];

    vector<bool> row(H,false);
    vector<bool> col(W,false);

    REP(i,H){
        REP(j,W){
            if(A[i][j]=='#'){
                row[i]=true;
                col[j]=true;
            }
        }
    }

    REP(i,H){
        if(row[i]){
            REP(j,W){
                if(col[j]){
                    cout << A[i][j];
                }
            }
            cout << endl;
        }
}

}