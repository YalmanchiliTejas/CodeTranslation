#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define int long long
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
const int INF = 1010000000;
const double EPS = 1e-10;
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

vector<int> init(int size){
  vector<int> par(size,-1);
  return par;
}

int root(int x, vector<int>& par){
  if(par[x] < 0){
    return x;
  }else{
    return par[x] = root(par[x],par);
  }
}

bool same(int x, int y, vector<int>& par){
  return root(x, par) == root(y, par);
}

void unite(int x, int y, vector<int>& par){
  x = root(x, par), y = root(y, par);
  if(same(x,y, par))return;
  par[x] += par[y];
  par[y] = x;
}

int size(int x, vector<int>& par){
  return -par[root(x, par)];
}

signed main(){
  int n,h=0,ans=0;cin>>n;
  rep(i,n){
    int a;cin>>a;
  if(h<=a){
   ans++;
    h=a;
  }
  }
  cout<<ans;
}
