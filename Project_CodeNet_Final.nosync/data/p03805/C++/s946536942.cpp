#include <ios>
#include <iomanip>
#include <iostream>
#include <functional>
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
#include <climits>

using namespace std;
typedef long long int ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1e9)
#define PI (acos(-1))
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
typedef pair <ll,ll> P;

int main()
{
    ll N, M;
    cin >> N >> M;
    ll adj[10][10] = {{}};
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        adj[a][b] = 1;
        adj[b][a] = 1; 
    }
    ll v[10];
    rep(i, 10) v[i] = i;
    ll ans = 0;
    do{
        if (v[0] != 0) continue;
        bool flag = false;
        rep(i, N-1) {
            if (adj[v[i]][v[i+1]] == 0) flag = true; 
        }
        if (!flag) {
            ans++;
        }
    }while(next_permutation(v,v+N));
    print(ans);
    return 0;
}
