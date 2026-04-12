#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define pye cout << "yes" << endl;
#define pno cout << "no" << endl;
#define pYe cout << "Yes" << endl;
#define pNo cout << "No" << endl;
#define pYE cout << "YES" << endl;
#define pNO cout << "NO" << endl;
#define end return 0;
#define prin(num) cout << num << endl;
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 100000000000
#define MOD 1000000007LL
#define MAX 200005
#define NIL -1
#define WHITE 0
#define BLACK 1
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

ll H, W;

int main(void) {
    ll i, j;
    cin >> H >> W;
    char a[H][W];
    ll cnt=0;
    for(i=0; i<H; i++) {
        for(j=0; j<W; j++) {
            cin >> a[i][j];
            if(a[i][j]=='#') cnt++;
        }
    }
    if(cnt==H+W-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    
}
