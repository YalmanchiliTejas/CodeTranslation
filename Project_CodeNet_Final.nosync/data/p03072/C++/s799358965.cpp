#/*
    AUTHOR:shivam51
    IIESTS
*/
  #include<bits/stdc++.h>
  using namespace std;
  //
  // #define MAX 100001
  #define md 998244353
  #define add accumulate
  #define ll long long int
  #define ld long double
  #define ff first
  #define ss second
  #define pb push_back
  #define mp make_pair
  #define vll vector<ll>
  #define lb lower_bound
  #define ub upper_bound
  #define pll pair<ll,ll>
  #define vpll vector<pll>
  #define all(v) v.begin(), v.end()
  #define rep(i,k,n) for(int i=k;i<n;i++)
  #define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
  #define repa(a,n) for(int i=a;i<n;i++)
  const int MAX=1e5+5;
  const int mod=1e9+7;
  const int N=3e5+9;
  const long double eps=1e-9;
  const ld PI=acos(-1.0);
    ll dx[]={1,0,-1,0};
	ll dy[]={0,1,0,-1};
  //
  //
  int main(){
  	hs;
  	ll n,ans=1,fst;	cin>>n;
  	cin>>fst;
  	rep(i,0,n-1){
  		ll k;
  		cin>>k;
  		ans+=(k>=fst);
  		fst=max(fst,k);
  	} 
  	cout<<ans;
  	return 0;
  }