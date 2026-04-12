#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>
#define ll int64_t
#define REP(i, n) for (ll i=0; i<n; i++)
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    int cnt = 0;
    REP (i, H) {
        REP (j, W) {
            cin >> A[i][j];
            if (A[i][j] == '#') {
                cnt++;
            }
        }
    }    

    if (cnt == H + W - 1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }


}