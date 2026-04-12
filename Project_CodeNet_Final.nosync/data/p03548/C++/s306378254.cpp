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


int main() {
    int x,y,z;
    scanf("%d %d %d", &x, &y, &z);
    int ans = ( x - z ) / ( y + z );
    printf ("%d\n", ans);
    return 0;
}
