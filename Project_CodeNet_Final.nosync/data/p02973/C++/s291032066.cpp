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
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll lis(vi A){
  ll n = A.size();
  vi dp(n,llINF);
  for(int i=0;i<n;i++){
    *upper_bound(ALL(dp),A[i]) = A[i];
  }
  return (lower_bound(ALL(dp),llINF)-dp.begin());
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  vi A(n);
  for(auto &a:A)cin>>a;
  reverse(ALL(A));
  cout<<lis(A)<<endl;
  return 0;
}
