#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
    int a,b,c,x,y;
    cin >> a>> b >> c >>x >> y;

    int sol1 = 0, sol2 = 0;
    // if (2*c < a+b)
    // {
    //     sol1 += 2*c*min(x,y);
    //     if (x < y) sol1 += (y-x) * b;
    //     else sol1 += (x-y) * a;
    // }else
    // {
    //     sol2 += a*x + b*y;
    // }

    sol1 += 2*c*min(x,y);
        if (x < y) sol1 += (y-x) * b;
        else sol1 += (x-y) * a;

    sol2 = a*x + b*y;
    int sol3 = 2*c*max(x,y);

    cout << min(min(sol1,sol2),sol3) << endl;

    return 0;
}