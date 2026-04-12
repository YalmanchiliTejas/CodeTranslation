/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){
    map <int,bool> row,colum;
    int n,m;
    cin >> n >> m ;
    string s[n];
    for (int i=0;i<n;i++) cin>>s[i];

    for (int i=0;i<n;i++){
        bool ok=true;
        for (int j=0;j<m;j++)
            if (s[i][j] == '#') ok=false ; 
        if (ok) row[i] = true ; 
    }
    for (int i=0;i<m;i++){
        bool ok=true;
        for (int j=0;j<n;j++)
            if (s[j][i] == '#') ok=false ; 
        if (ok) colum[i] = true ; 
    }
    for (int i=0;i<n;i++){
        if (!row[i]){
          for (int j=0;j<m;j++){
              if (!colum[j]) cout << s[i][j] ; 
          }
          cout << endl ; 
        }
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
