#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#define REP(i, n) for(int i=0; i<(n); i++)
#define FOR(i, a, n) for(int i=(a); i<(n); i++)
using namespace std;

int main(){
    int r,g,b;cin>>r>>g>>b;
    string ans = (10*g+b)%4 == 0 ? "YES":"NO";
    cout << ans << endl;
    return 0;
}