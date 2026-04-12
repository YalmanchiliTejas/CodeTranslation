/*
      Ashraful Islam Paran
      27-August-2020
      09:51:48
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f(n) for (int i = 0; i < n; i++)
#define fo(i, x, n) for (int i = x; i < n; i++)
#define fb(i, x, n) for (int i = n - 1; i <= 0; i--)
#define w(t) int t; cin >> t; while (t--)



typedef unsigned long long ull;
typedef vector<long long> vi;
#define ull unsigned long long
#define msi map<string, long long>
#define mii map<long long, long long>
const int MX = 2e5 + 5;
const int INF = 1e18;
#define pb push_back
#define endl "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define all(x) x.begin(), x.end()
#define ff first
#define ss second


int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,b;
    cin>>a>>b;
    if(a==b)
    {
        yes;
    }
    else
    {
        no;
    }
    
    
    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}