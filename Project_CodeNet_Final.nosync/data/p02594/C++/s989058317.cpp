/* Arpit Pandey*/ 

#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdint.h>
using namespace std;
 
#define int long long
#define pb push_back
#define in insert
#define F first
#define S second
#define mod 1000000007
#define endl '\n'
#define test(x) int x;cin>>x; while(x-->0)
#define memset(a,b) memset(a,b,sizeof(a))
#define debug(x) cout << "[ " << #x  << " : " << x << " ]" << endl;
 
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
}
void sol()
{
  int n;cin>>n;
  if(n>=30)
    cout<<"Yes";
  else
    cout<<"No";
}

int32_t main()
{
    fast_io();
    //test(t)
    sol();
    
    //cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    //cerr << sizeof(dp)*(1e-6) << " megabytes\n";
    return 0;
}
