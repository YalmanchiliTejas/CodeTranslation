#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <cctype>
#include <cmath>

using namespace std;

/* typedef */

typedef long long ll;

/* constant */

const int INF = 1 << 30;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */

/* function */
void printAns(bool can);

/* main */
int main(){

    int n, q, k;
    bool can;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> k;
        auto it = lower_bound(a.begin(), a.end(), k);
        int dist = it - a.begin();
        cout << dist << '\n';
    }

    //printAns(can);
}

void printAns(bool can) {
    if (can)
        cout << 1 << '\n';
    else 
        cout << 0 << '\n';
}

