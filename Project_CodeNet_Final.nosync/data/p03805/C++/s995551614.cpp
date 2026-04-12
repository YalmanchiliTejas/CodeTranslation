#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

int ans = 0;
bool e[9][9] = {{}}; //edge
int n,m;
void ss( int a, bool* b){
    //printf ("%d\n", a);
    for (int i = 1; i <= n+1; i++){
        if( i == n+1 ){ ans++; return; }
        if( !b[i] ) break;
    }
    for (int i = 1; i <= n; i++){
        if(e[a][i] && !b[i]){
            b[i] = true;
            ss(i,b);
            b[i] = false;
        }
    }
}

int main() {

    int a, b;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        e[a][b] = true;
        e[b][a] = true;
    }

    bool c[9] = {};
    c[1] = true;
    ss(1, c);

    printf ("%d\n", ans);

    return 0;
}