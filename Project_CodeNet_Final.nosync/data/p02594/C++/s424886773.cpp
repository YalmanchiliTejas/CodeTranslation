#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define per(i,n,a) for(ll i=n-1;i>=a;i--)
#define nl "\n"
#define LLMAX 1e18
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define fastread cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
#define online_judge

const ll MOD=1e9+7;

ll pow(ll n, ll e){
  if(e==0)
    return 1;
  else if(e==1)
    return n;
  else if(e%2==0)
    return pow(n,e/2);
  else
    return pow(n,e/2)*n;
}

bool prime(ll n){
  ll ct=0;
  rep(i,2,sqrt(n)+1){
    if(n%i==0)
      return false;
  }
  return true;
}

void solve(){
  fastread;
  ll n,m,temp,mi,q,ma=0,t;
  
  cin >> n;
  (n>=30)?cout << "Yes":cout << "No";
}

int main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  #endif
  clock_t start, end;
  start = clock();
  solve();
  end=clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cerr << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cerr << " sec " << endl;
  return 0;
}