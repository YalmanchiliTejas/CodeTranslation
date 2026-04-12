#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second
 
template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}
 
typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  int x=0,y=0;
  FOR(i,1,n+1){
	x+=800;
    if(i%15==0) y+=200;
  }
  cout<<x-y<<endl;
}