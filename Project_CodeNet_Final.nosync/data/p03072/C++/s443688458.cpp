/*
 * Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$
**/

#include <bits/stdc++.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <cmath>

using namespace std;

//typedef
typedef string STR;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef priority_queue<int> PQI;
typedef vector<LL> VLL;
typedef vector<ULL> VULL;
typedef vector<STR> VS;
typedef vector<char> VC;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<STR,int> PSI;
typedef pair<int,STR> PIS;
typedef vector<PII> VII;
typedef map<int,int> MII;
typedef map<LL,LL> MLL;
typedef map<STR,int> MSI;
typedef map<char,int> MCI;
typedef map<int,STR> MIS;
typedef set<STR> SS;
typedef set<int> SI;
typedef set<LL> SLL;

//symbolic const
#define MOD 1000000007
#define MAXN 1e9
#define SIZE 10000

//STL keywords
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
#define all(v) v.begin(), v.end()

//functions
#define dec(n) cout<<fixed<<setprecision(n);
#define f(i, n)   for(LL i=0; i<n; i++)
#define fa(i,a,n) for(LL i=a; i<n; i++)

//IO
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test int t;cin>>t;while(t--){solve();}

LL maxLL(LL a, LL b){return (a>b?a:b);}
LL minLL(LL a, LL b){return (a<b?a:b);}

void solve() {
  int n;
  cin>>n;
  VI h(n), a(n, 0);
  int c=0;
  f(i, n){
      cin>>h[i];
      if(i==0) a[i]=h[i];
      else a[i]=max(h[i], a[i-1]);
      if(a[i]==h[i]) c++;
  }
  cout<<c;
}

int main() {
    sync;
    //test;
    solve();
    return 0;
}
