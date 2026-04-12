#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
//#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <map>
#include <numeric>
using namespace std;
#define fin << '\n'
#define finl << '\n';
#define finn cout << '\n'
#define unless(flg) if(!(flg))
#define alles(obj) obj.begin(), obj.end()
// bashise
#define elif else if
#define echo cout <<
#define read cin >>
// javaise
#define bash push_back
#define makePair make_pair
#define isEmpty empty
// germanise
#define drucken(obj) cout << obj << '\n'
#define lesen(obj) cin >> obj
#define fur for
#define wenn if
#define sonst else
#define Zahl int
// type-define
#define String string
#define Stack stack
#define Queue queue
#define pQueue priority_queue
#define Vector vector
#define Pair pair
#define Map map
typedef long long llong;
typedef bool boolean;
typedef Pair<int,int> Pii;
typedef Vector<int> Vi;
// utils
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
boolean isMovable(int x,int y,int w,int h){return (x>=0&&y>=0&&x<w&&y<h);};
const int INF = 1 << 29;

Vi vi;
int  ans[200100];

signed main(){
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    read n;
    for ( int i = 0; i < n; i++ ) {
        int a;
        read a;
        vi.bash(a);
    }
    reverse(alles(vi));
    int pos = 0;
    for ( int i = 0; i < n/2; i++ ) {
        ans[i] = vi[pos++];
        ans[n-i-1] = vi[pos++];
    }
    if ( n&1 ) {
        ans[n/2] = vi[pos++];
    }
    echo ans[0];
    for ( int i = 1; i < n; i++ ) { 
        echo ' ' << ans[i];
    }
    echo endl;

    return 0;
}
