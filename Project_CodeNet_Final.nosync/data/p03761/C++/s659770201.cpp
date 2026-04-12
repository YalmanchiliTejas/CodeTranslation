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
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
using namespace std;

inline void solve(){ 
    int n;
    cin >> n;
    string s;
    map <char,int> m[n];
    for (int i=0;i<n;i++){
        cin>>s;
        int l=sz(s);
        for (int j=0;j<l;j++){
            m[i][s[j]]++;
        }
    }
    vector<int> ans(26,0);
    
    for (char c='a',j=0;c<='z';c++,j++){
        int cnt=1000;
        for (int i=0;i<n;i++){
            cnt = min(m[i][c],cnt);
        }
        ans[j]=cnt;
    }
    for (int i=0;i<26;i++){
        for (int j=0;j<ans[i];j++){
          cout << (char) (i+'a');
        }
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
