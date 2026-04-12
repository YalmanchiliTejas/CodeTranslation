//kalyanchirla
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
using namespace std;
#define int long long
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define csl ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007

int32_t main()
{ 
    csl;

    int n;
    cin >> n;

    int arr[n]; 

    for(int i=0;i<n;i++) cin >> arr[i];

    vi suff(n+1,0);

    for(int i=n-1;i>=0;i--)
    {
        suff[i] =  (suff[i+1]%mod + arr[i]%mod)%mod;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(((arr[i]%mod)*suff[i+1]%mod)%mod);
    }
    cout << sum%mod << "\n";
}