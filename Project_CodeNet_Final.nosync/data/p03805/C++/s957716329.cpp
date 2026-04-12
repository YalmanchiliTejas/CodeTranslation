#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <numeric>
#include <queue>
#define rep(i,s,n) for (int i=s;i<n;++i)
#define drep(i,s,n) for (int i=n;i>=s;--i)
#define all(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define print(x) cout<<(x)<<endl
using namespace std;
typedef long long ll;

int gcd(int a,int b)
{if (a%b == 0) return(b);
 else          return(gcd(b,a%b));}
int lcm(int a,int b)
{return a*b/gcd(a,b);}
void printv(vector<auto> v) {cout<<'[';rep(i,0,v.size()){cout<<v[i]<<',';}cout<<']'<<endl;}
void printvv(vector<vector<auto>> vv)
{
  cout<<'['<<endl;
  rep(q,0,vv.size()){cout<<'[';rep(p,0,vv.at(q).size())cout<<vv.at(q).at(p)<<',';cout <<']'<<endl;}
  cout<<']'<<endl;
}
void solve(); int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}
int step_x[] = {-1,0,0,1};
int step_y[] = {0,-1,1,0};
//------------------------------------------------------------
int n,m,ans=0;
int g[10][10];

void solve() {
  cin>>n>>m;

  rep(i,0,m)
  {
    int a,b;
    cin>>a>>b;
    g[a][b]=g[b][a]=1;
  }

  vector<int> x;

  rep(i,2,n+1) x.push_back(i);

  do
  {
    int flag=1;
    rep(i,0,x.size())
    {
      int y=(i==0?1:x[i-1]);
      if(!g[y][x[i]]) flag=0;
    }
    if(flag) ans++;
  }while(next_permutation(all(x)));
  print(ans);

  return;
}
