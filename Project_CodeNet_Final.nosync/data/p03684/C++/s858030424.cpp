#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include <stdio.h>
#include <string.h>

using namespace std;

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define vi vector<int>
#define vl vector<long>
#define vll vector<ll>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector< pair<int,int> >
#define ll long long
#define ld long double 
#define str string
// freopen("firesafe.in", "r", stdin);
// freopen("firesafe.out", "w", stdout);
vector<pair<int,int> >a;
vector<pair<int,int> >b;
//map<ll,ll>mmap;
vector<pair<int , pair<int,int> > >g;
vector<int> p;

int dsu_get (int v) {
  return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
  a = dsu_get (a);
  b = dsu_get (b);
  if (rand() & 1)
    swap (a, b);
  if (a != b)
    p[a] = b;
}
int main(){
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
    int aa,bb;
    cin>>aa>>bb;
    a.pb(mp(aa,i));
    b.pb(mp(bb,i));
   }
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
   for(int i=n-1;i>0;i--){
      g.pb(mp((a[i].fi-a[i-1].fi),mp(a[i].se,a[i-1].se)));
      g.pb(mp((a[i].fi-a[i-1].fi),mp(a[i-1].se,a[i].se)));
   }
   for(int i=n-1;i>0;i--){
      g.pb(mp((b[i].fi-b[i-1].fi),mp(b[i].se,b[i-1].se)));
      g.pb(mp((b[i].fi-b[i-1].fi),mp(b[i-1].se,b[i].se)));
   }
   

 int cost = 0;
    vector < pair<int,int> > res;

    sort (g.begin(), g.end());
    p.resize (n);
    for (int i=0; i<n; ++i)
      p[i] = i;
          for (int i=0; i<sz(g); ++i) {
            int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
            if (dsu_get(a) != dsu_get(b)) {
              cost += l;
              res.push_back (g[i].second);
              dsu_unite (a, b);
            }
          }
    cout<<cost<<endl;
}