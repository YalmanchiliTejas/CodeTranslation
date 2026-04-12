#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define For(i, a) for (int i=0; i<a; i++)
#define FORR(i,a,b) for (int i = a; i >= b; i--)
#define Forr(i,a) for (int i = a; i >= 0; i--)

#define deb(...) cerr << "[" << #__VA_ARGS__ << "] : [", DBG(__VA_ARGS__)
void DBG() { cerr << "]\n";}
template<typename T, typename ...Args> void DBG(T first, Args... args)
{cerr << first; if(sizeof...(args))cerr<<", "; DBG(args...); }

#define int ll
#define pb(x) push_back(x)
#define INF (int)1e17
#define PI 3.14159265358979323846

int del_x[4] = {-1, 1, 0, 0};
int del_y[4] = {0, 0, 1, -1};
int XX[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int YY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};


const int mod = 1e9+7;

int mul(int x,int y){
    int res = x*y;
    if(res >= mod)res%=mod;
    return res;
}

int add(int x, int y){
    int res = x+y;
    if(res >= mod)res-=mod;
    return res;
}
int sub(int x, int y){
    int res = x-y;
    if(res<0)res+=mod;
    return res;
}

void solve(){
  int n; cin >> n;
  int a[n];
  For(i,n)cin >> a[i];
  vector<int> pref(n+1,0);
  pref[0]=a[0];
  FOR(i,1,n)pref[i]=add(pref[i-1],a[i]);
  int ans=0;
  For(i,n){
    ans = add(ans, mul(a[i],sub(pref[n-1],pref[i])));
  }
  cout  << ans << "\n";
}
int32_t main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    for(int tt=1;tt<=t;tt++){
        solve();
    }
}