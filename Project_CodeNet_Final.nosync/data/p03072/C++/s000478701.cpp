#include <bits/stdc++.h>
using namespace std;
#define itn int
#define nibu(K,x) binary_search(K.begin(),K.end(),x)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define pb push_back
#define mp make_pair
#define Fi first
#define Se second
#define out(x) cout<<x<<endl
#define put(x) out(x)
#define in(x) cin>>x
#define maxx(a,b,c) max(a,max(b,c))
#define minn(a,b,c) min(a,min(b,c))
using ll = long long;
using vl = vector<ll>;
using vs = vector<string>;
const double pi = 3.14159265358979;

int main() {
ll N;
  in(N);
  vl H(N);
  rep(i,N) in(H[i]);
  int ans = 0;
  rep(i,N){
   bool f = true;
    for(int j=0;j<i+1;j++){
      if(H[j]>H[i]) f = false; 
    }
    if(f) ans++;
  }
  out(ans);
}
