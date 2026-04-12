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
#define REP(i, n) for(i=0; i<n; i++)
#define REPR(i, n) for(i=n; i>=0; i--)
#define FOR(i, m, n) for(i=m; i<n; i++)
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 1LL<<32
#define MOD 1000000007LL
#define MAX 100005
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> doup;


int main(void) {
    ll h, w;
    cin >> h >> w;
    char a[100][100];
    ll i, j;
    set<ll> ch, cw;
    for(i=0; i<h; i++) {
        for(j=0; j<w; j++) {
            cin >> a[i][j];
        }
    }
    ll flag=0;
    for(i=0; i<h; i++) {
        flag=0;
        for(j=0; j<w; j++) {
            if(a[i][j]=='#') flag=1;
        }
        if(flag==0)
            ch.insert(i);
    }
    flag=0;
    for(j=0; j<w; j++) {
        flag=0;
        for(i=0; i<h; i++) {
            if(a[i][j]=='#') flag=1;
        }
        if(flag==0)
            cw.insert(j);
    }
    
    ll flag2=0;
    for(i=0; i<h; i++) {
        for(j=0; j<w; j++) {
            auto it1=ch.find(i);
            auto it2=cw.find(j);
            flag2=0;
            if(it1!=ch.end()) flag2=1;
            if(it1!=ch.end() || it2!=cw.end())
                continue;
            else cout << a[i][j];
        }
        if(flag2==1);
        else cout << endl;
    }
    
}
