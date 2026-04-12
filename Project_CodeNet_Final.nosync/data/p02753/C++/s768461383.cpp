/*
#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
*/
#include <bits/stdc++.h>

#define iosb ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define BIT(x) __builtin_popcount(x)
#define all(x) x.begin() , x.end()
#define F first
#define S second
#define pb push_back

using namespace std ;

typedef unsigned long long UL ;
typedef long long L ;
typedef string T ;
typedef int I ;

const I MaxN =      1e5+1 ;
const I MOD =       1e9+7 ;
const I inf =       2e9+7 ;
const L INF = 2e18+7 ;

int32_t main()
{
    //freopen(".in" , "r" , stdin) ;
    //freopen(".out" , "w" , stdout) ;
    string s ;
    cin >> s ;
    if(s[0] == 'B' && s[1] == 'B' && s[2] == 'B')
        cout << "No" ;
    else if (s[0] == 'A' && s[1] == 'A' && s[2] == 'A')
        cout << "No" ;
    else
    {
        cout << "Yes" ;
    }
    
}