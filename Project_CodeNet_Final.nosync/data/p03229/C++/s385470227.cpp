#include <bits/stdc++.h>
using namespace std;
#define fol(i,n) for(int i=0;i<n;++i)
#define pb push_back
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vip;

int main(){
  int n;cin>>n;
  int a[n];
  fol(i,n){cin>>a[i];}
  sort(a,a+n);
  long long ans = 0;
  long long b1=0,b2=0;
  if(n%2){
    int s = n/2;
    int mid = a[s];
    int am = a[0];
    int bm = a[s-1];
    int an = a[n-1];
    int bn = a[s+1];
    fol(i,n){
      if(i==s)continue;
      ans+= a[i]*(i<s?-2:2);
    }
    ans -= min({mid-am,bn-mid,an-mid,mid-bm});
  }else{
    int s = n/2;
    fol(i,n){
      ans+= a[i]*(i<s?-2:2);
    }
    ans -= min({a[s]-a[0],a[s]-a[s-1],a[n-1]-a[s-1],a[n-1]-a[0]});
  }
  cout << ans << endl;
  return 0;
}
