#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define INF 1e9
typedef long long int ll;
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x;
    return is;
}

ll gcd(ll m, ll n)
{
    if ((0 == m) || (0 == n))
        return 0;
    while (m != n)
    {
        if (m > n)
            m = m - n;
        else
            n = n - m;
    }
    return m;
}

ll lcm(ll m, ll n)
{
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}

vector<ll> decom;

void decompositPrime(ll n)
{
    ll a = 2;
    while (n >= a * a)
    {
        if (n % a == 0)
        {
            decom.push_back(a);
            n /= a;
        }
        else
        {
            a++;
        }
    }
    decom.push_back(n);
}

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){
    bool all_visited = true;

    REP(i,N){
        if(visited[i]==false)
            all_visited = false;
    }

    if(all_visited)
        return 1;
    
    int ret = 0;
    REP(i,N){
        if(graph[v][i]==false)  continue;
        if(visited[i])  continue;

        visited[i]=true;
        ret+=dfs(i,N,visited);
        visited[i]=false;
    }
    return ret;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    REP(i,M){
        cin >> a[i] >> b[i];
        graph[a[i]-1][b[i]-1] = graph[b[i]-1][a[i]-1] = true;
    }

    bool visited[nmax];
    REP(i,N){
        visited[i] = false;
    }

    visited[0]=true;
    cout << dfs(0,N,visited) << endl;

    return 0;
}