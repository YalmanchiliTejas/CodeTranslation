#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;
const double PI = acos(-1.0);
const string alp = "abcdefghijklmnopqrstuvwxyz";
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string HEX = "0123456789ABCDEF";
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int main(void) {
    int x,y,z,i;
    cin >> x >> y >> z;
    cout << (x-z)/(y+z);
    return 0;
}
