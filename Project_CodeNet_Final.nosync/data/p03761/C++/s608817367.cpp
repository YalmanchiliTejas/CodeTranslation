#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#define debug(x) cerr << #x << ':' << x << endl
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    map<char,int> MIN_of;
    for(char c='a'; c<='z'; c++)
        MIN_of[c]=1e9;
    REP(i,n){
        map<char,int> A;
        for(char c='a'; c<='z'; c++)
            A[c]=0;
        string si;
        cin >> si;
        for(auto c : si)
            A[c]++;
        for(auto c : A){
            MIN_of[c.first] = min(MIN_of[c.first], c.second);
        }
    }
    string ans="";
    for(char c='a';c<='z'; c++)
        REP(i,MIN_of[c]) ans.push_back(c);

    cout << ans << endl;

    return 0;
}