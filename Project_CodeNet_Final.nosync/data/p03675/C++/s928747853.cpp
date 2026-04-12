#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdint.h>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <tuple>
#include <unordered_set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int main() {
//     5 3 1 2 4
// 6 4 2 1 3 5
    int n;
    cin >> n;
    VI a(n);
    REP(i, n) scanf("%d", &a[i]);
    VI ans;
    for (int i = n; i >= 1; i -= 2) {
        ans.PB(a[i - 1]);
    }
    int i = n % 2 ? 2 : 1;
    for (; i <= n; i += 2) {
        ans.PB(a[i - 1]);
    }
    REP(i, n) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}