#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 29)
#define MOD 1000000007
//int dx[4] = {1,0,0,-1};
//int dy[4] = {0,1,-1,0};


int main(){
  
  int n;
  cin >> n;
  vector<int> v(n);
  REP(i,n)cin >> v[i];
  int res = 1;
  for(int i = 1;i < n;i++){
    if(v[i] >= *max_element(v.begin(),v.begin()+i))res++;
  }
  cout << res << endl;

  



  return 0;
}
