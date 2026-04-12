#include <iostream>
#include <cassert>
#include <climits>
#include <bitset>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <tuple>
#include <time.h>
#include <random>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

long long int INF = 3e18;
double Pi = 3.1415926535897932384626;

vector<ll> G[500005];
//vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//ll bit[500005];
//↓,→,↑,←


#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define re(i,n) for(i=0;i<n;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl


ll mod = 1000000007;
ll rui(ll number1,ll number2){

    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll gcd(ll number1,ll number2){

    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }
}
void YES(bool condition){

    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){

    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}

/*
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=800000; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
	rfact[800000] = rui(fact[800000],mod - 2);
	for(ll i=800000; i>=1; i--){
	   rfact[i-1] = rfact[i] * i;
	   rfact[i-1] %= mod;
	}
	return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod) * rfact[n-r]) % mod;}
*/

ll n,m,num,sum,ans,a,b,c,d,e,g,h,w,i,j,k,q,l,r;
ll x[500005],y[500005],z[500005];
//bool used[500005];
bool flag,dame;
ll dp1[500005],dp2[500005];
 
ll dfs1(ll v,ll p){
   ll a = 0;
   for(int i=0;i<G[v].size();i++){
	  ll nv = G[v][i];
	  if(nv == p)continue;
	  dp1[nv] = dfs1(nv,v);
	  if(dp1[nv] % 2 == 0){
		 a++;
	  }
   }
   dp1[v] = a;
   return a;
}


void dfs2(ll v,ll p){
   ll num = 0;
   if(dp1[v] % 2 == 1){
	  num = n % 2;
   }else{
	  num = (n + 1) % 2;
   }
   if(num % 2 == 1){
	  dp2[v] = dp1[v] + 1;
   }else{
	  dp2[v] = dp1[v];
   }
   for(int i=0;i<G[v].size();i++){
	  ll nv = G[v][i];
	  if(nv == p)continue;
	  dfs2(nv,v);
   }
   return;
}

int main(){
	cin >> n;
	for(i=0;i<n-1;i++){
	   cin >> a >> b;
	   G[a].pb(b);
	   G[b].pb(a);
	}
	a = dfs1(1,-1);
	for(i=1;i<=n;i++){
	   //pe(i);p(dp1[i]);
	}
	dp2[1] = dp1[1];
	for(int i=0;i<G[1].size();i++){
	   ll nv = G[1][i];
	   dfs2(nv,1);
	}
	ll flag = false;
	for(i=1;i<=n;i++){
	   //pe(i);p(dp2[i]);
	   if(dp2[i] >= 2)flag = true;
	}
	if(flag){
	   p("First");
	}else{
	   p("Second");
	}
	return 0;
}