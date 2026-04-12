#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi acos(-1.0)

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;


char inv(char c){
    if(c == 'S') return 'W';
    if(c == 'W') return 'S';
    return 0;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s, row;
    cin >> n >> s;
    s += s[0];
    s += s[1];
    vector<string> patterns = {"SS", "SW", "WS", "WW"};
    for(auto &p : patterns){
        row = p;
        FOR(i, 1, n){
            if(s[i] == 'o'){
                if(row[i] == 'S') row += row[i-1];
                if(row[i] == 'W') row += inv(row[i-1]);
            }else if(s[i] == 'x'){
                if(row[i] == 'S') row += inv(row[i-1]);
                if(row[i] == 'W') row += row[i-1];
            }
        }
        if(row[0] == row[n] && row[1] == row[n + 1]){
            row.pop_back();
            row.pop_back();
            cout << row << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
