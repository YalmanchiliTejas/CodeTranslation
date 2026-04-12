#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;++i) cin>>A[i];
  sort(A.begin(), A.end());
  ll ans = 0;
  if(N==2) {
    ans = A[1]-A[0];
    cout<<ans<<endl;
    return 0;
  }
  else{
    ll a=A[0], b=A[N-1];
    ans += b-a;
    int l=1, r=N-2;
    ll c, d;
    ll tmp1, tmp2, tmp3, tmp4;
    while(l<=r){
      c = A[l];
      d = A[r];
      tmp1 = abs(c-a);
      tmp2 = abs(c-b);
      tmp3 = abs(d-a);
      tmp4 = abs(d-b);
      if(tmp1>=tmp2 && tmp1>=tmp3 && tmp1>=tmp4){
        ans += abs(c-a);
        a = c;
        l++;
      }
      else if(tmp2>=tmp1 && tmp2>=tmp3 && tmp2>=tmp4){
        ans += abs(c-b);
        b = c;
        l++;
      }
      else if(tmp3>=tmp1 && tmp3>=tmp2 && tmp3>=tmp4){
        ans += abs(d-a);
        a = d;
        r--;
      }
      else{
        ans += abs(d-b);
        b = d;
        r--;
      }
    }
    cout<<ans<<endl;
    return 0;
  }
}
