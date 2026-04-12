#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <bitset>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
#define rep(i,n) for(i = 0; i < (n); ++i)
#define rrep(i,n) for(i = 1; i <= (n); ++i)
#define drep(i,n) for(i = (n)-1; i >= 0; --i)
#define fin(ans) cout<<(ans)<<endl
#define P 1000000007
#define STI(s) atoi(s.c_str())//string to int
#define mp(p,q) make_pair(p,q)
#define Sort(a) sort(a.begin(),a.end())
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const int INF = INT_MAX;
const long long LLINF = 1LL<<60;
//g++ -std=c++1z main.cpp
//./a.exe

bool isPrime(int x){
    int i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}


int main(void){ios::sync_with_stdio(false);cin.tie(0);
//////////////////////////////////////////////////////
   int n,i;
   cin >> n;
   int h[n];
   rep(i,n)cin>>h[i];
   int max=0;
   int ans=0;
   rep(i,n){
       if( h[i]>=max ){
           max = h[i];
           ans ++; 
       }
   }
   cout << ans << endl;


//////////////////////////////////////////////////////
return 0;}