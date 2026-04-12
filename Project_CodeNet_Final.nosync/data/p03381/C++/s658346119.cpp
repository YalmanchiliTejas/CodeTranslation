#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <cassert>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

typedef long long ll;

const int N = 200005;

struct node
{
        int a, b, c;
} v[N];
bool cmp1(node a, node b)
{
        return a.a < b.a;
}
bool cmp2(node a, node b)
{
        return a.b < b.b;
}

int main()
{
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n; cin >> n;
        for(int i = 1; i <= n; ++i) cin >> v[i].a, v[i].b = i;
        sort(v+1,v+1+n,cmp1);
        for(int i = 1; i <= n; ++i) cerr << v[i].a << ' ' << v[i].b << ' ' << v[i].c << endl;
        for(int i = 1; i <= n; ++i)
        {
                if(i <= n/2) v[i].c = v[(n+2)/2].a;
                else v[i].c = v[n/2].a;
        }
        sort(v+1,v+1+n,cmp2);
        for(int i = 1; i <= n; ++i) cout << v[i].c << '\n';
        return 0;
}
