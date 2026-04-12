#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cctype>
#include <cstring>
#include <set>
#include <map>
#define rep(i, m, n) for (int i = m; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define ll long long
#define ull unsigned long long
#define push(a) push_back(a)
#define pop(a) pop_back(a)
#define debug(x) cout << #x << ": " << x << endl
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};

ll n, m, a, b, c, d, sum = 0;
ll graph[1005][1005] = {}, s, g, v, p;
int x,y,z;

int main()
{
    cin >> x >> y >> z;
    x -= z;
    x /= (y+z);
    cout<<x<<endl;
}