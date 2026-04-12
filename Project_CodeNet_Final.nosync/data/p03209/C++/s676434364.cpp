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
using namespace std;
using i64 = int64_t;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep2(i, x, n) for(int i=x;i<n;++i)
#define INF 1<<29;

i64 rec(int cur, i64 x, vector<i64>& p, vector<i64>& l)
{
    if(cur == 0)
        return x > 0 ? 1 : 0;

    if(2*x < l[cur])
        return rec(cur-1,x-1,p,l);
    else
        return rec(cur-1,x-l[cur-1]-2,p,l) + p[cur-1] + 1;
}

int main()
{
    i64 n,x;
    cin >> n >> x;

    vector<i64> p(51);
    vector<i64> l(51);
    p[0] = l[0] = 1;
    rep(i,50) p[i+1] = 2*p[i]+1;
    rep(i,50) l[i+1] = 2*l[i]+3;

    cout << rec(n,x,p,l) << endl;

    return 0;
}