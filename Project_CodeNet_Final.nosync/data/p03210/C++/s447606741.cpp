/*
author: Apoorv Singh
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef vector <int> vi;
typedef vector <long long> vl;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ll long long
#define pb push_back   
#define all(c) c.begin(), c.end()
#define watch(x) cout << (#x) << " " << (x) << endl;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = a; i > b; --i)
#define um unordered_map
#define F first
#define S second

ll modulo = 1e9 + 7;

template <class X>

void printarr(X arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

ll fpow(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n&1)
            ans = (ans * a)%modulo;
        a = (a*a)%modulo;
        n = n >> 1;
    }
    return ans;
}

/*
const int M = 1e6 + 10;
int composite[M] = {0};

void sieve()
{
    FOR(i,2,M)
    {
        if (!composite[i])
        {
            for (int j = 2*i; j < M; j += i)
                composite[j] = max(composite[j], i);
        }
    }
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    cin >> x;
    if (x == 3 or x == 5 or x == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}