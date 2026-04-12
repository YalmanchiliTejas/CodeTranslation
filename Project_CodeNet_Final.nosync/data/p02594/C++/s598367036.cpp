//****************************//
/**********  main *************/
//****************************//
#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define REP(i, n) for(i = 0; i < n; i++)
#define FOR(i, a, b) for(i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())

double pi = 3.141592653589793;

int gcd(int a, int b) {
    if(a % b == 0) {
        return (b);
    } else {
        return (gcd(b, a % b));
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int x ;
    cin >> x ;

    x >= 30 ? (cout << "Yes" << endl) : (cout << "No" << endl);



    return 0;
}
