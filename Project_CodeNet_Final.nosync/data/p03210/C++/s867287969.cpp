#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <queue>
#include <stack>
#include <string.h>
#include <list>
using namespace std;
typedef long long ll;
#define all(a)  (a).begin(), (a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define rep(i,n) for(int i = 0; i < n; i++)
#define repR(i,n) for(int i = n; i >= 0; i--)
#define FOR(i,m,n) for(int i = m; i < n; i++)
#define PB push_back
#define MP make_pair
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main(){
    int x; cin >> x;
    string res;
    if(x == 7 || x == 5 || x == 3)res = "YES";
    else res = "NO";
    cout << res << endl;
    return 0;
}