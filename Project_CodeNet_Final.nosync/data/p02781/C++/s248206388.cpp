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
#define lint unsigned long long int
#define FOR(x, to) for(int x=0; x<(int)(to); x++)
#define DUMP(ar) for(auto itd=begin(ar); itd != end(ar); itd++) cout << "["s << itd - begin(ar) << "]:"s << *itd << endl
#define DUMPL(ar) for(auto itd=begin(ar); itd != end(ar); itd++) { cout << *itd; if(end(ar)-itd > 1) cout << ' '; } cout << endl
#define COUT(x) cout << (x) << endl
#define VCIN(ar) for(auto &vcin: (ar)) cin >> vcin
#define ALL(ar) ar.begin(), ar.end()
#define LOOPD(i) cout << "ループ["s << i << "]回目---------------"s << endl
using namespace std;
// lint:64ビット 10^19

int n;
vector<vector<vector<int>>> dp(200, vector<vector<int>>(200, vector<int>(2, -1)));

int rec(string &s, int nonzero_num=0, int k=0, bool tight=true){
    if(k >= (int)s.size()){
        return nonzero_num == n;
    }

    int x = s[k] - '0';
    int r = tight ? x : 9;
    int &res = dp[k][nonzero_num][tight];
    if(res != -1) return res;
    
    res = 0;
    for(int i=0; i<=r; i++){
        res += rec(s, nonzero_num + (i!=0), k+1, tight && i == r);
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;
    cin >> n;

    int ans = rec(str);
    cout << ans << endl;

    return 0;
}