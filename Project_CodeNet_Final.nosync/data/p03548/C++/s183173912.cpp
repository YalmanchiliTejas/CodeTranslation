#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include <cmath>
#include <map>
#include <climits>
using namespace std;
using Int = long long;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n,m) for(int i=n;i<m;i++)
int main()
{
    int X, Y, Z; cin >> X >> Y >> Z;
    cout << (X - Z) / (Y + Z) << endl;
    return 0;
}