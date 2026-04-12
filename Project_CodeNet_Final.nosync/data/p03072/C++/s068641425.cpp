#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;
#define MOD 1000000007

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline T gcd(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template<class T> inline T lcm(T a,T b){return a*b/gcd(a,b);}

const ll INF = 1LL << 60;

int main(){
  int n;
  cin >> n;
  int h[100];
  FOR(i,n){
    cin >> h[i];
  }
  int maxi=h[0];
  int ans=1;
  for(int i=1;i<n;i++){
    if(h[i]>=maxi){
      ans++;
      maxi=h[i];
    }
  }
  cout << ans << endl;
}
