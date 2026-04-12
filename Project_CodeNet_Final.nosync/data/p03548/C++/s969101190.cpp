#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
#define lps(i,j,n) for(int i=j;i<n;i++)
#define fordebug int hoge;cin>>hoge;
#define DEKAI 1000000007;
#define INF (1LL<<60)
#define int long long
#define double long double
#define floot10 cout<<fixed<<setprecision(10)
#define Int long long

int min(int a,int b){
  if(a<b) return a;
  return b;
}
int max(int a,int b){
  if(a>b) return a;
  return b;
}

int gcd(Int a, Int b) {
  return b != 0 ? gcd(b, a % b) : a;
}
int lcm(Int a, Int b) {
  return a / gcd(a, b)*b;
}
// a x + b y = gcd(a, b)
int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

vector<int> g[100010];
int done[100010];



signed main(){
  int x,y,z;
  cin>>x>>y>>z;
  int ans=0;
  x-=(z*2+y);
  if(x<0)cout<<0<<endl;
  else{
    ans++;
    while(1){
      x-=y+z;
      if(x<0){
	cout<<ans<<endl;
	return 0;
      }
      ans++;
    }
  }
  return 0;
}
 
