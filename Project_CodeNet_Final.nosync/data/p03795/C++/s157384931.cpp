/**
    __author__ : p4mf
    problems_ID:
*/

#include <cstdio>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
#define sz(x)          (int)((x).size(x))
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define REP(i, y)  for (__typeof(x) i = 0; i < y; i++)
#define REPI(i, y)  for (__typeof(x) i = y; i > 0; i--)
typedef long long      ll;
typedef pair<int, int> P;
typedef pair<P, int>   PP;
typedef vector<int>    VV;
typedef vector<P>      VVP;
typedef vector<PP>     VVPP;
const   int            INF = 2<<20;
const   double         EPS = 1E-8;

int main() {
    sci(N);
    int ate = N*800;

    int y = ((int)floor(N/15))*200;
    printf("%d", ate-y);
}