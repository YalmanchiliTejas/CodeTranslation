#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define REP(i, n) for(i=0; i<n; i++)
#define REPR(i, n) for(i=n; i>=0; i--)
#define FOR(i, m, n) for(i=m; i<n; i++)
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 10000000000
#define MOD 1000000007LL
#define MAX 100005
#define NIL -1
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<double, double> doup;

int main(void) {
    ll H, W;
    cin >> H >> W;
    char c[100][100];
    bool R[100], C[100];
    ll i, j;
    
    for(i=0; i<H; i++) {
        for(j=0; j<W; j++) {
            cin >> c[i][j];
        }
    }
    
    for(i=0; i<H; i++) {
        R[i]=false;
        for(j=0; j<W; j++) {
            if(c[i][j]=='#')
                R[i]=true;
        }
    }
    for(j=0; j<W; j++) {
        C[j]=false;
        for(i=0; i<H; i++) {
            if(c[i][j]=='#')
                C[j]=true;
        }
    }
    
    for(i=0; i<H; i++) {
        if(R[i]) {
            for(j=0; j<W; j++) {
                if(C[j]) {
                    cout << c[i][j];
                }
            }
            cout << endl;
        }
        
    }
}
