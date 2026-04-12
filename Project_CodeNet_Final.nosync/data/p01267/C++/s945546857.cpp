#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<iomanip>
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;
typedef long long ll;
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<string> vs;
Def inf = sizeof(Def) == sizeof(ll) ?2e18:1e9+10;
int main(){
  int n,a,b,c,x;
  while(cin>>n>>a>>b>>c>>x,n){
    int co=0;
    vi in(n);
    rep(i,n)cin>>in[i];
    int t=0;
    while(t!=n){
      if(x==in[t])t++;
      if(t==n)break;
      co++;
      x=(a*x+b)%c;
      if(co>10000)break;
    }
    if(co<=10000)cout<<co<<endl;
    else cout<<-1<<endl;
  }
}

