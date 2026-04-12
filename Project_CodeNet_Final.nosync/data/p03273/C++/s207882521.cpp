#include <bits/stdc++.h>
#define MODNum 1000000007
#define REP(type, i, a, b) for( type i = a; i < b; i++ )
typedef long long ll;

using namespace std;

int main (void) {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> C(H, vector<char>(W));
    vector<int> x;
    vector<int> y;
    REP(int,i,0,H) REP(int,j,0,W) cin >> C.at(i).at(j);
    REP(int,i,0,H){
        bool Flag = false;
        REP(int,j,0,W) if ( C.at(i).at(j) == '#') Flag = true;
        if ( Flag ) y.push_back(i);
    }
    //REP(int,i,0,x.size()) cout << x.at(i) << endl;
    REP(int,j,0,W){
        bool Flag = false;
        REP(int,i,0,H) if ( C.at(i).at(j) == '#') Flag = true;
        if ( Flag ) x.push_back(j);
    }
    //REP(int,i,0,x.size()) cout << y.at(i) << endl;
    for ( auto i : y ){
        for ( auto j : x ) cout << C.at(i).at(j);
        cout << endl;
    }
    return 0;
}