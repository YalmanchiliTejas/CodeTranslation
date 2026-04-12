#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define c(n) cin>>n
#define co(n) cout<<n<<endl
using namespace std;
typedef long long ll;
typedef vector<long> vl;
typedef vector<string> vs;

int main(){
  int a=0,n,c=0;
  c(n);
  int h[n];
  rep(i,0,n){
    c(h[i]);
    if(h[i]>=a){
      c++;
      a=h[i];
    }
  }
  co(c);
    
  return 0;
}