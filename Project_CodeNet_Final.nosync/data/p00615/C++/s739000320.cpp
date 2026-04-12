#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

void solve(){
}

int main(){
  int n,m;
  while(cin>>n>>m,n||m){
    vector<int> v(n+m);
    rep(i,n+m){
      cin>>v[i];
    }
    v.push_back(0);
    sort(v.begin(),v.end());

    int ans = 0;
    REP(i,1,n+m+1){
      ans = max(ans,v[i] - v[i-1]);
    }
    cout<<ans<<endl;
  }
}