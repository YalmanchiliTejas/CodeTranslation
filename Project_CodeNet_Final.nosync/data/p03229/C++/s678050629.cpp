#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  vi A(n);
  for(auto &a:A)cin>>a;
  sort(ALL(A));
  if(n%2 == 0){
    ll ans = 0;
    for(int i=0;i<n/2-1;i++){
      ans -= 2*A[i];
    }
    ans -= A[n/2-1];
    ans += A[n/2];
    for(int i=n/2+1;i<n;i++){
      ans += 2*A[i];
    }
    cout<<ans<<endl;
  }else{
    ll sum = 0,sum2 = 0;
    for(int i=0;i<n/2-1;i++){
      sum -= 2*A[i];
    }
    sum -= A[n/2-1]+A[n/2];
    for(int i=n/2+1;i<n;i++){
      sum += 2*A[i];
    }

    for(int i=0;i<n/2;i++){
      sum2 -= 2*A[i];
    }

    sum2 += A[n/2]+A[n/2+1];
    for(int i=n/2+2;i<n;i++){
      sum2 += 2*A[i];
    }
    //  cout<<sum<<" "<<sum2<<endl;
    cout<<max(sum,sum2)<<endl;
  }
  return 0;
}
