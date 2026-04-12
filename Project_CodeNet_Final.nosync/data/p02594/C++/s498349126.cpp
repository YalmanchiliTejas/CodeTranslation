#include <bits/stdc++.h>

#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

using namespace std;

#define F first
#define S second 

#ifdef __debug_leywar
#include <debug/debugger.h>
#else
#define db(...) ;
#endif

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  
    int n ; 
    cin >> n ;

    cout << ( n >= 30 ? "Yes" : "No" ) ;

    return 0;
}