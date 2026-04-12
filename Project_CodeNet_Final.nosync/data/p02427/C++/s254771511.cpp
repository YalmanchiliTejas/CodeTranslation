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
#include <set>
#include <stack>
#include <cctype>
#include <cmath>
#include <bitset>

using namespace std;

/* typedef */
typedef long long ll;

/* constant */
const int INF = 1 << 30;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;

/* global variables */

/* function */

/* main */
int main(){

    int n; cin >> n;
    // 1 ============================
    int upper = pow(2, n);

    for (int i = 0; i < upper; i++) {
        bitset<18> bs(i);
        printf("%d:", i);
        for (int j = 0; j < n; j++) {
            if ((bs>>j)[0]) printf(" %d", j);
        } 
        printf("\n");
    }
    /*
    // 2 ===========================
    for (int b = 0;b < (1 << n); b++) {
        printf("%d:", b);
        for (int i = 0; i < n;i++)
            if( (b >> i) & 1)
                printf(" %d", i);
    cout<<"\n";
    }
    */

}

