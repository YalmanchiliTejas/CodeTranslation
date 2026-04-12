#include <bits/stdc++.h>
using namespace std;
#define fol(i,n) for(int i=0;i<n;++i)
#define pb push_back
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vip;

int skl(int a){
  a%=10;
  return a!=0?10-a:0;
}

int main(){
  int n;cin>>n;
  int h[n];
  fol(i,n)cin>>h[i];
  int ans = 0;
  int mx = 0;
  fol(i,n){
    if(mx<=h[i]){
      ans++;
    }
    mx = max(mx,h[i]);
  }
  cout << ans << endl;
  return 0;
}
