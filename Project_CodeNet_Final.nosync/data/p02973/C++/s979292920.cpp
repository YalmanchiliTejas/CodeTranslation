#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define int long long
#define set multiset
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

int pow(int x, int n){
  if(n == 0)return 1;
  if(n % 2 == 0)return pow(x * x % MOD, n/2);
  else return x * pow(x, n-1) % MOD;
}


int n;int a[210000];
signed main(){
  cin>>n;rep(i,n){
    cin>>a[i];
    a[i] *= -1;
  }
  set<int> st;
  rep(i,n){
    auto itr = st.upper_bound(a[i]);
    if(itr != st.end())st.erase(itr);
    st.insert(a[i]);
  }
  cout << st.size() << endl;
}
