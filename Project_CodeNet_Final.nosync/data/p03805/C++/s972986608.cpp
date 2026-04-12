#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int ans=0;
int n,m;
vi v[8];
vi used(8,0);

void dfs(int now,int time){
  int i;
  if(time==0){
    bool c=true;
    rep(i,n)
      if(used[i]==0)c=false;
    if(c)ans++;
    used[now]--;
    return;
  }
  rep(i,v[now].size()){
    used[v[now][i]]++;
    dfs(v[now][i],time-1);
  }
  used[now]--;
}

int main(void) {
  cin>>n>>m;
  int i;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  used[0]++;
  dfs(0,n-1);
  cout<<ans<<endl;
}
