#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <math.h>
#include <queue>
#include <stdio.h>
using namespace std;
using i64 = int64_t;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep2(i, x, n) for(int i=x;i<n;++i)

int main()
{    
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int n = max(x,y);
    int min_p = a*x + b*y;
    int p = min_p;

    rep(i,n)
    {
        if(i<x) p -= a;
        if(i<y) p -= b;
        p += 2*c;
        min_p = min(min_p,p);
    }
    cout << min_p << endl;
    return 0;
}