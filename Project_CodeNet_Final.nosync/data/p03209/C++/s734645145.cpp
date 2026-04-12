#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define llu long long unsigned
#define vvi vector< vector<int> >
#define vi vector<int>
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define shosu(X) fixed << setprecision(X)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
 
int n;
llu x;

llu int f(int lv){
  llu int res = 1;
  REP(i, lv+2) res *= 2;
  return res - 3;
}

llu int g(int lv){
  llu int res = 1;
  REP(i, lv+1) res *= 2;
  return res - 1;
}
llu int rec(llu int nokori, int now){
  llu int ans = 0;
  if(now == 0){
    return 1;
  }else{
    if(nokori == 1) return 0;
    else if(nokori <= 1 + f(now-1)) return rec(nokori-1, now-1);
    else if(nokori == 2 + f(now-1)) return (1 + rec(nokori-2, now-1));
    else if (nokori <= 2 + 2 *f(now-1)) return (1 + g(now-1) + rec(nokori - 2 - f(now-1), now-1));
    else return (1 + g(now-1) + rec(nokori - 3 - f(now-1), now-1));
  }
}
int main(){
  cin >> n >> x;
  cout << rec(x, n) << endl;
}