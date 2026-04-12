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

string solve(){ 
    int n; cin>>n;
    string s; cin>>s;
    string r;
    string h[4]={"ss","sw","ws","ww"};
    for (int i=0;i<4;i++){
        r=h[i][0]; r+=h[i][1];
        for (int i=1;i<n;i++){
            if (s[i]=='o' and r[i-1]=='s' and r[i]=='s') r+='s';
            if (s[i]=='o' and r[i-1]=='w' and r[i]=='s') r+='w';
            if (s[i]=='o' and r[i-1]=='s' and r[i]=='w') r+='w';
            if (s[i]=='o' and r[i-1]=='w' and r[i]=='w') r+='s';

            if (s[i]=='x' and r[i-1]=='w' and r[i]=='s') r+='s';
            if (s[i]=='x' and r[i-1]=='s' and r[i]=='s') r+='w';
            if (s[i]=='x' and r[i-1]=='w' and r[i]=='w') r+='w';
            if (s[i]=='x' and r[i-1]=='s' and r[i]=='w') r+='s';
        }
        //cout << r << endl; 
        if (s[n-1]=='o'){
            if ( r[n-1]=='w' and r[0] != r[n-2] ) {
                if (s[0]=='x' and r[0]=='w' and r[n-1] == r[1]) return r.substr(0,n);
                if (s[0]=='x' and r[0]=='s' and r[n-1] != r[1]) return r.substr(0,n);
                if (s[0]=='o' and r[0]=='w' and r[n-1] != r[1]) return r.substr(0,n);
                if (s[0]=='o' and r[0]=='s' and r[n-1] == r[1]) return r.substr(0,n);
            }
            if ( r[n-1]=='s' and r[0] == r[n-2] ) {
                if (s[0]=='x' and r[0]=='w' and r[n-1] == r[1]) return r.substr(0,n);
                if (s[0]=='x' and r[0]=='s' and r[n-1] != r[1]) return r.substr(0,n);
                if (s[0]=='o' and r[0]=='w' and r[n-1] != r[1]) return r.substr(0,n);
                if (s[0]=='o' and r[0]=='s' and r[n-1] == r[1]) return r.substr(0,n);
            }
        }
        else {
            if ( r[n-1]=='s' and r[0] != r[n-2] ) {
                if (s[0]=='x' and r[0]=='w' and r[n-1] == r[1]) return r.substr(0,n);
                if (s[0]=='x' and r[0]=='s' and r[n-1] != r[1]) return r.substr(0,n);
                if (s[0]=='o' and r[0]=='w' and r[n-1] != r[1]) return r.substr(0,n);
                if (s[0]=='o' and r[0]=='s' and r[n-1] == r[1]) return r.substr(0,n);
            }
            if ( r[n-1]=='w' and r[0] == r[n-2] ) {
                if (s[0]=='x' and r[0]=='w' and r[n-1] == r[1]) return r.substr(0,n);
                if (s[0]=='x' and r[0]=='s' and r[n-1] != r[1]) return r.substr(0,n);
                if (s[0]=='o' and r[0]=='w' and r[n-1] != r[1]) return r.substr(0,n);
                if (s[0]=='o' and r[0]=='s' and r[n-1] == r[1]) return r.substr(0,n);
            }
        }
        
        r="";
    }
    return "";
}

signed main()
{
    int n=1; //cin>>n;
    while (n--){
        string res = solve();
        if (res.size()){
          int l=res.size();
          for (int i=0;i<l;i++){
            cout << (char)(res[i]-32);
          }
          cout << endl;
        }
        else 
          cout << -1 << endl;
    }
        
    return 0;
}
