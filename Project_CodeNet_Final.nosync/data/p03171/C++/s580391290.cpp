#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#include <numeric>
#define lint long long int
#define FOR(x, to) for(int x=0; x<(int)(to); x++)
#define DUMP(ar) for(auto itd=begin(ar); itd != end(ar); itd++) cout << "["s << itd - begin(ar) << "]:"s << *itd << endl
#define DUMPL(ar) for(auto itd=begin(ar); itd != end(ar); itd++) { cout << *itd; if(end(ar)-itd > 1) cout << ' '; } cout << endl
#define COUT(x) cout << (x) << endl
#define VCIN(ar) for(auto &vcin: (ar)) cin >> vcin
#define ALL(ar) ar.begin(), ar.end()
#define LOOPD(i) cout << "ループ["s << i << "]回目---------------"s << endl
using namespace std;
// lint:64ビット 10^19
using P = pair<lint, bool>;
vector<int> a;
vector<vector<P>> mm(3001, vector<P>(3001, make_pair(0, false)));

lint rec(int left, int right, bool turn=true){ // turn=true...x+  false...y+
    if(left == right){
        if(turn == true) return a[right];
        else return -a[right];
    }

    if(mm[left][right].second) return mm[left][right].first;
    lint ans = 0;
    lint tmp1 = rec(left+1, right, !turn) + (turn ? a[left] : -a[left]);
    lint tmp2 = rec(left, right-1, !turn) + (turn ? a[right] : -a[right]);
    if(turn){
        // tmp1 += a[left];
        // tmp2 += a[right];
        ans = max(tmp1, tmp2);
    }else{
        // tmp1 -= a[left];
        // tmp2 -= a[right];
        ans = min(tmp1, tmp2);
    }

    mm[left][right].first = ans;
    mm[left][right].second = true;

    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    a.resize(n);
    VCIN(a);

    lint ans = rec(0, a.size()-1);
    cout << ans << endl;

    // cout << "縦:left, 横:right" << endl;
    // cout << "  ";
    // for(int i=0; i<4; i++){
    //     cout << setw(4) << i << ' ';
    // }
    // cout << endl;
    // for(int i=0; i<4; i++){
    //     cout << i << ' ';
    //     for(int j=0; j<4; j++){
    //         cout << setw(4) << mm[i][j].first << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;
}