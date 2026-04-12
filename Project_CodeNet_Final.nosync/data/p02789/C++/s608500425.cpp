#include<iostream>
#include<iomanip>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
#include<tuple>
#include<numeric>
#include<map>
#include<cmath>
#define ll long long
#define mod 1000000000+7
#define rep(i,n) for(int i=0;i<(int) (n);i++)
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;

  if(n==m)cout<<"Yes";
  else cout<<"No";
  return 0;
}
