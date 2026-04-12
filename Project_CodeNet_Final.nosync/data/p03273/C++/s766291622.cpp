#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include<bitset>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
const int inf = 1e9 + 7;

#define nd second
#define st first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 6;
const int logN = 17;

int n, m, arr[123][123], h1[123], h2[123];
char c, cc[123][123];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            scanf(" %c", &c);
            if(c == '.') arr[i][j] = 0;
            else arr[i][j] = 1;
            cc[i][j] = c;
        }
    for(int i = 1; i <= n; i++) {
        int t = 0;
        for(int j = 1; j <= m; j++)
            t += arr[i][j];
        if(t == 0) h1[i] = 1;
    }
    for(int i = 1; i <= m; i++) {
        int t = 0;
        for(int j = 1; j <= n; j++)
            t += arr[j][i];
        if(t == 0) h2[i] = 1;
    }
    for(int i = 1; i <= n; i++)
        if(!h1[i]) {
            for(int j = 1; j <= m; j++)
                if(!h2[j]) {
                    cout << cc[i][j];
                }
            cout << endl;
        }
}