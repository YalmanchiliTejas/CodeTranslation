#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>

#define PB push_back
#define MP make_pair
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define INF (1<<30)
#define LLINF (1<<60)
#define MOD 1000000007
#define REP(i, n) for(int i=0;i<n;i++)
using ll = long long;
using namespace std;

int a, b, c, x, y;

int main() {
    cin >> a >> b >> c >> x >> y;
    if (a + b <= c * 2) {
        cout << a * x + b * y << endl;
    }
    else {
        int m = min(x, y);
        if (x == y) {
            cout << c * x * 2 << endl;
        }
        else if(x > y) {
            if (a >= c * 2) {
                cout << c * 2 * m + c * 2 * (x - m) << endl;
            }
            else {
                cout << c * 2 * m + a * (x - m) << endl;
            }
        }
        else {
            if (b >= c * 2) {
                cout << c * 2 * m + c * 2 * (y - m) << endl;
            }
            else {
                cout << c * 2 * m + b * (y - m) << endl;
            }
        }
    }
    return 0;
}
