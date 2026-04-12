#pragma GCC optimize ("O3")
#include<bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <string>
#include <stdbool.h>

#include <cstring>

#define pb push_back
#define p push

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ll long long

#define getI(a) scanf("%d",&a)
#define getII(a, b) scanf("%d%d",&a,&b)
#define getIII(a, b, c) scanf("%d%d%d",&a,&b,&c)
#define getL(a) scanf("%lld",&a)
#define getLL(a, b) scanf("%lld%lld",&a,&b)
#define getLLL(a, b, c) scanf("%lld%lld%lld",&a,&b,&c)
#define BEND(c) (c).begin(),(c).end()
#define BEND2(c) (c).rbegin(),(c).rend()
#define fi first
#define se second
#define pi 3.1415926535897932384626
#define getS(a) scanf("%s",a)
#define pfb(a) printf("%.10lf\n",a);
#define pfi(a) printf("%d",a);
#define pfii(a, b) printf("%d%d",a,b);
#define pfl(a) printf("%lld",a);
#define pfll(a, b) printf("%lld%lld",a,b);
#define pfd(a) printf("%.12lf ",a);
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define endl "\n"

#define MOD  ( int)(1e9 + 7)
#define MAXN (ll) ((1e6+5))
#define K 25
#define  ALPHABET_SIZE  26
#define N (int)(1e5+10)
#define sag (sol|1)
#define sol (root<<1)
#define ort (bas+son)/2
#define INF (ll )1e18
#define int ll
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<pair<int,int>>> vvpi;
typedef vector<long long> vl;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<long long, long long>> vpl;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<vi> graph ;


signed main() {
    string s ;
    cin >> s ;
    char c= s[0];
    bool ctr = 0 ;
    for (int i = 1; i <s.size() ; ++i) {
        if(c != s[i])ctr=1;
    }
    if(ctr)cout<<"Yes";
    else cout << "No";

    return 0;









}