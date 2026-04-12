#include <stdio.h>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <utility>

using namespace std;

#define pb push_back
#define ft first
#define sd second
#define mpr make_pair
#define all(x) begin((x)), end((x))
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define max3(a, b, c) max((a), max((b), (c)))
#define max4(a, b, c, d) max(max((a), (b)), max((c), (d)))
#define min3(a, b, c) min((a), min((b), (c)))
#define min4(a, b, c, d) min(min((a), (b)), min((c), (d)))
#define isz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef pair<int, int> pii;
typedef vector<int> vi;

/* <------------------------------------------------------------------------------------> */

deque<int> q;

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int a;
        scanf("%d", &a);
        if (n & 1)
        {
            if (i & 1) q.push_back(a);
            else q.push_front(a);
        }
        else
        {
            if (i & 1) q.push_front(a);
            else q.push_back(a);
        }
    }
    while (!q.empty())
    {
        printf("%d ", q.back());
        q.pop_back();
    }
    puts("");
}

/* <------------------------------------------------------------------------------------> */

// #define LOCAL
// #define FILE_NAME

int main()
{
    #if defined LOCAL
        freopen("input.txt", "r", stdin);
    #elif defined FILE_NAME
        freopen(FILE_NAME".in", "r", stdin);
        freopen(FILE_NAME".out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
