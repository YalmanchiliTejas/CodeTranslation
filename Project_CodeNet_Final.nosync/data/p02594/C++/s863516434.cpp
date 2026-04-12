/*
    Author : zzugzx
    Lang : C++
    Blog : blog.csdn.net/qq_43756519
*/
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define SZ(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
//const int mod = 998244353;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int maxn = 2e6 + 10;
const int N = 2e4 + 5;
const ll inf = 0x3f3f3f3f;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    int x;
    cin >> x;
    if (x >= 30) cout << "Yes" << endl;
    else cout << "No" << endl;
}
