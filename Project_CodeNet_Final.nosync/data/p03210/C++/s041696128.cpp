#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <list>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <cmath>
#define rep(i,m,n) for(int i=m; i<(n); i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
typedef long long ll;
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x;
    cin >> x;
    if(x==3 || x==5 || x==7) cout << "YES";
    else cout << "NO";
}
